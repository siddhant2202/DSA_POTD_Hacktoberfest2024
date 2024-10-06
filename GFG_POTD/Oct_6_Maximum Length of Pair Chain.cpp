#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxChainLength(vector<pair<int, int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int maxLength = 1;
    int end = pairs[0].second;

    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i].first > end) {
            maxLength++;
            end = pairs[i].second;
        }
    }
    
    return maxLength;
}

int main() {
    vector<pair<int, int>> pairs = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    cout << "Maximum Length of Pair Chain: " << maxChainLength(pairs) << endl;
    return 0;
}

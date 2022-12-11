#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<ll, int> getFreeValue(int v, const vector<vector<int>> &tree, const vector<pair<int, int>> &ivals) {
    auto [L, R] = ivals[v];
    if (tree.size() == 0) { // leaf node
        return {R, 1};
    } else {
        pair<ll, int> finalCount{0, 0};
        for (auto c : tree[v]) {
            auto [subFree, subPath] = getFreeValue(c, tree, ivals);
            finalCount.first += subFree;
            finalCount.second += subPath;
        }
        if (L <= finalCount.first && finalCount.first <= R) {
            // do nothing yay 
        } else if (finalCount.first > R) {
            finalCount.first = R;
        } else { // make new path, set freevalue to R
            finalCount.second++;
            finalCount.first = R;
        }
        return finalCount;
    }
}

int solve() {
    int n; scanf("%d", &n);
    vector<vector<int>> tree(n);
    vector<pair<int, int>> ivals(n);
    for (int i = 1; i < n; ++i) {
        int pi; scanf("%d", &pi);
        tree[pi-1].push_back(i);
    }
    for (int i = 0; i < n; ++i) scanf("%d %d", &ivals[i].first, &ivals[i].second);
    auto [rootFV, pathCount] = getFreeValue(0, tree, ivals);
    return pathCount;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}
#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000100;
using ll = long long;

struct rurm {
    int al, ar;
    ll rmax, lazy;
    rurm *left, *right;
    void combine() {
        rmax = max(left->rmax, right->rmax);
    }
    void propagate() {
        if (lazy != 0) {
            rmax += lazy;
            if (left != nullptr) {
                left->lazy += lazy;
                right->lazy += lazy;
            }
            lazy = 0;
        }
    }
    rurm(int i, int j) : al(i), ar(j), rmax(0), lazy(0), left(nullptr), right(nullptr) {
        if (al != ar) {
            int k = (i + j) / 2;
            left = new rurm(al, k);
            right = new rurm(k + 1, ar);
        }
    }
    ll rangeMax(int i, int j) {
        propagate();
        if (ar < i || j < al) return -INF;
        else if (i <= al && ar <= j) return rmax;
        else return max(left->rangeMax(i, j), right->rangeMax(i, j));
    }
    void rangeDelta(int i, int j, ll v) {
        if (i > j || j < 0) return;
        i = max(i,0);
        propagate();
        if (ar < i || j < al) return;
        else if (i <= al && ar <= j) {
            lazy += v;
            propagate();
        } else {
            left->rangeDelta(i, j, v);
            right->rangeDelta(i, j, v);
            combine();
        }
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<int> height(n), beauty(n);
    for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &beauty[i]);
    vector<ll> dp(n);
    rurm optTable(0, n - 1);
    vector<pair<int, int>> addRanges;
    addRanges.emplace_back(-1, -INF);

    dp[0] = beauty[0];
    optTable.rangeDelta(0, 0, beauty[0]);
    addRanges.emplace_back(0, height[0]);

    int dominator = 0;
    for (int i = 1; i < n; ++i) {
        if (height[i] < height[dominator]) dominator = i;
        dp[i] = beauty[dominator];
    }
    
    for (int i = 1; i < n; ++i) {
        vector<pair<int, int>> checkValues;
        while (height[i] < addRanges.back().second) {
           checkValues.push_back(addRanges.back());
            addRanges.pop_back();
        }
        checkValues.push_back(addRanges.back());
        int chead = i - 1;
        for (auto [toRemove, value] : checkValues) {
//            printf("check value %d %d chead %d\n", toRemove, value, chead);
            if (toRemove != checkValues[0].first && height[chead] > height[i]) optTable.rangeDelta(toRemove, chead - 1, -beauty[chead]);
//            printf("here\n");
            chead = toRemove;
        }
//        printf("finalizing\n");
        optTable.rangeDelta(max(0, addRanges.back().first), i - 1, beauty[i]);
        dp[i] = max(dp[i], optTable.rangeMax(0, i-1));
//        printf("dp %d = %lld\n", i, dp[i]);
        optTable.rangeDelta(i, i, dp[i]);
        addRanges.emplace_back(i, height[i]);
    }
    printf("%lld\n", dp.back());
        
}
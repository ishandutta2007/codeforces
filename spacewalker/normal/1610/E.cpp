#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int SLMAX = 40;

int solve() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<ll> auniq;
    for (int v : a) if (auniq.empty() || v != auniq.back()) auniq.push_back(v);
    int k = auniq.size();
    vector<int> maxLen(k); // does not include start
    for (int i = 0; i + 1 < k; ++i) {
        maxLen[i] = 1;
        ll nextMin = 2 * auniq[i+1] - auniq[i];
//        printf("start %lld at >= %lld\n", auniq[i], auniq[i+1]);
        while (nextMin <= auniq.back()) {
            ++maxLen[i];
            ll nextElem = *lower_bound(begin(auniq), end(auniq), nextMin);
            nextMin = 2 * nextElem - auniq[i];
        }
    }

    map<int, int> occs;
    for (int v : a) occs[v]++;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
//        printf("start at %d? %d %d\n", i, occs[auniq[i]], maxLen[i]);
        ans = max(ans, occs[auniq[i]] + maxLen[i]);
    }
    return n - ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}
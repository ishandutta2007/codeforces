#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 1000000000000000000;

ll minSteps(vector<int> src, vector<int> dst) {
    ll ans = 0;
    int n = src.size();
    vector<vector<int>> sfollow(2), dfollow(2);
    vector<int> scts(2), dcts(2);
    for (int i = n - 1; i >= 0; --i) {
        sfollow[src[i]].push_back(scts[1-src[i]]);
        dfollow[dst[i]].push_back(dcts[1-dst[i]]);
        ++scts[src[i]]; ++dcts[dst[i]];
    }
    if (scts[0] != dcts[0]) return INF;
    for (int dig = 0; dig < 2; ++dig) {
        for (int i = 0; i < sfollow[dig].size(); ++i) ans += max(0, dfollow[dig][i] - sfollow[dig][i]);
    }
    return ans;
}

ll solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int &v : arr) v %= 2;
    vector<int> tg1(n), tg2(n);
    for (int i = 0; i < n; ++i) (i % 2 == 0? tg1 : tg2)[i] = 1;
    return min(minSteps(arr, tg1), minSteps(arr, tg2));
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll ans = solve();
        if (ans == INF) printf("-1\n");
        else printf("%lld\n", ans);
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve() {
    int n; scanf("%d", &n);
    vector<int> ca(n), cb(n);
    for (int i = 0; i < n; ++i) scanf("%d", &ca[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &cb[i]);
    for (int &v : ca) --v;
    for (int &v : cb) --v;
    vector<int> inlined(n);
    for (int i = 0; i < n; ++i) inlined[ca[i]] = cb[i];
    vector<bool> vis(n);
    vector<int> csizes;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int ci = i, cs = 0;
        while (!vis[ci]) {
            ++cs;
            vis[ci] = true;
            ci = inlined[ci];
        }
        csizes.push_back(cs);
    }
    int toAdd = 0, toDeduct = 0;
    for (int v : csizes) {
        toAdd += v / 2;
        toDeduct += v / 2;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i <= toDeduct) ans -= 2 * i;
        if (n - i < toAdd) ans += 2 * i;
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
}
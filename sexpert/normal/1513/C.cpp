#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
ll ans[10][MAXN];

void precalc(int d) {
    vector<ll> cnt(10);
    cnt[d] = 1;
    for(int m = 0; m < MAXN; m++) {
        ll s = accumulate(cnt.begin(), cnt.end(), 0LL);
        ans[d][m] = s % MOD;
        vector<ll> tc(10);
        for(int i = 0; i < 9; i++)
            tc[i + 1] = cnt[i];
        tc[0] = (tc[0] + cnt[9]) % MOD;
        tc[1] = (tc[1] + cnt[9]) % MOD;
        cnt = tc;
    }
}

void solve() {
    string s;
    int m;
    cin >> s >> m;
    ll tot = 0;
    for(auto &c : s)
        tot = (tot + ans[c - '0'][m]) % MOD;
    cout << tot << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int d = 0; d < 10; d++)
        precalc(d);

    int t;
    cin >> t;
    while(t--)
        solve();
}
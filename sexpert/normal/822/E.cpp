#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 9;
vector<ll> bases = {37, 71};

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

struct hsh {
    vector<ll> po[2], iv[2], ha[2];
    hsh(string s = "*") {
        for(int i = 0; i < bases.size(); i++) {
            po[i].clear();
            iv[i].clear();
            ha[i].clear();
            ll b = bases[i], ib = inv(b);
            po[i].push_back(1);
            iv[i].push_back(1);
            ha[i].push_back(0);
            for(auto c : s) {
                po[i].push_back(po[i].back() * b % MOD);
                iv[i].push_back(iv[i].back() * ib % MOD);
                ha[i].push_back((ha[i].back() + po[i].back() * c) % MOD);
            }
        }
    }
};
hsh hs, ht;

string s, t;

bool eq(int l1, int r1, int l2, int r2) {
    for(int i = 0; i < bases.size(); i++) {
        ll x = ((hs.ha[i][r1] - hs.ha[i][l1 - 1]) * hs.iv[i][l1 - 1]) % MOD;
        ll y = ((ht.ha[i][r2] - ht.ha[i][l2 - 1]) * ht.iv[i][l2 - 1]) % MOD;
        if(x < 0)
            x += MOD;
        if(y < 0)
            y += MOD;
        if(x != y)
            return false;
    }
    return true;
}

int lcp(int p, int q) {
    if(s[p - 1] != t[q - 1])
        return 0;
    int lo = 1, hi = min(s.size() - p + 1, t.size() - q  + 1);
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(eq(p, p + mi - 1, q, q + mi - 1))
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

const int MAXN = 1e5 + 5;
ll dp[MAXN][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> s >> m >> t >> x;
    hs = hsh(s), ht = hsh(t);
    for(int k = 0; k < x; k++) {
        for(int ps = 0; ps <= n; ps++) {
            dp[ps][k + 1] = max(dp[ps][k + 1], dp[ps][k]);
            if(ps < n && dp[ps][k] < m) {
                dp[ps + 1][k] = max(dp[ps + 1][k], dp[ps][k]);
                int l = lcp(ps + 1, dp[ps][k] + 1);
                dp[ps + l][k + 1] = max(dp[ps + l][k + 1], dp[ps][k] + l);
            }
        }
    }
    for(int k = 0; k <= x; k++) {
        for(int ps = 0; ps <= n; ps++) {
            if(dp[ps][k] == m) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}
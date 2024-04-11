#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int mod = (int)1e9 + 7;
const int N = 705;

string str;


int dp[N][N][2];

ll solve(int d, int rem, bool flag, int v) {
    if(rem < 0) return 0;
    if(d == -1) return rem == 0;
    if(~dp[d][rem][flag]) return dp[d][rem][flag];
    int lim = flag ? str[d] - '0' : 9;
    ll res = 0;
    for (int i = 0; i <= lim; i++) {
        res += solve(d - 1, rem - (i >= v), flag && lim == i, v);
        if(res >= mod) res -= mod;
    }
    return dp[d][rem][flag] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    ll res = 0;
    reverse(all(str));
    rep(b, 1, 10) {
        memset(dp, -1, sizeof(dp));
        ll p1 = 0;
        rep(i, 1, sz(str) + 1) {
            p1 = (p1 * 10 + 1) % mod;
            res += solve(sz(str) - 1, i, true, b) * p1;
            res %= mod;
        }
    }
    cout << res << '\n';

}
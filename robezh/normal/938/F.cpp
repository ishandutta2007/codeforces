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

const int N = 5005, INF = (int)1e9;

struct P {
    pii p;
    int idx;
};

int n;
string str;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x3f, sizeof dp);
    cin >> str;
    n = sz(str);
    int k = 0;
    while((1 << (k + 1)) <= n) k++;
    int m = n - ((1 << k) - 1);
    for (int j = 0; j < (1 << k); j++) dp[m - 1][j] = str[j + (m - 1)] - 'a';
    for (int i = m - 2; i >= 0; i--) {
        vector<P> ps;
        for (int mask = 0; mask < (1 << k); mask++) {
            dp[i][mask] = dp[i + 1][mask];
        }
        for (int mask = (1 << k) - 1; mask >= 0; mask--) {
            rep(j, 0, k) {
                if(mask >> j & 1) dp[i][(mask ^ (1 << j))] = min(dp[i][(mask ^ (1 << j))], dp[i][mask]);
            }
            ps.push_back({{str[i + mask] - 'a', dp[i][mask]}, mask});
        }
        sort(all(ps), [&](const P &p0, const P &p1) {
            return p0.p < p1.p;
        });
        rep(j, 0, sz(ps)) {
            dp[i][ps[j].idx] = j;
        }
    }
    int cur = 0;
    string res;
    rep(i, 0, m) {
        int nxt = -1;
        rep(mask, 0, 1 << k) {
            if(mask & cur) continue;
            if(nxt == -1 || dp[i][cur ^ mask] <= dp[i][nxt]) nxt = (cur ^ mask);
        }
        cur = nxt;
        res.push_back(str[i + cur]);
    }
    cout << res << '\n';
}
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

const int N = 20, INF = (int)1e9;

int n;
string str[N];
vi cnt[N];
int mn[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> str[i];
        cnt[i].resize(2 * sz(str[i]) + 1, 0);
        for (char c : str[i]) {
            sum[i] += (c == '(' ? 1 : -1);
            mn[i] = min(mn[i], sum[i]);
            if(sum[i] == mn[i]) {
                cnt[i][mn[i] + sz(str[i])]++;
//                cout << i << " " << mn[i] << endl;
            }
        }
    }
    vi s(1 << n, 0), dp(1 << n, -INF), dp2(1 << n, -INF);
    dp[0] = dp2[0] = 0;
    rep(mask, 0, 1 << n) {
        rep(j, 0, n) s[mask] += (mask >> j & 1) * sum[j];
    }
    int res = 0;
    rep(mask, 0, 1 << n) {
        res = max({res, dp2[mask], dp[mask]});
        rep(i, 0, n) {
            if(mask >> i & 1) continue;
            int idx = -s[mask] + sz(str[i]);
            int nval = (dp[mask] + (0 <= idx && idx < sz(cnt[i]) ? cnt[i][idx] : 0));
//            cout << mask << ", " << i << ": " << nval << " " << -s[mask] <<  endl;
            if(mn[i] + s[mask] < 0) dp2[mask ^ (1 << i)] = max(dp2[mask ^ (1 << i)], nval);
            else dp[mask ^ (1 << i)] = max(dp[mask ^ (1 << i)], nval);
        }
    }
    cout << res << '\n';
}
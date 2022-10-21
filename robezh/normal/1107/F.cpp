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

const int N = 505;
const ll INF = (ll)1e18;

struct P {
    int a, b, k;
} p[N];

int n;
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> p[i].a >> p[i].b >> p[i].k;
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.b > p2.b;
    });
    fill(dp, dp + N, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
//        cout << p[i].b << ": ";
        for (int j = n; j >= 0; j--) {
            ll mx = dp[j] + max(0LL, p[i].a - 1LL * p[i].b * p[i].k);
            if(j) mx = max(mx, dp[j - 1] + p[i].a - 1LL * (j - 1) * p[i].b);
            dp[j] = mx;
        }
//        rep(j, 0, n + 1) cout << dp[j] << " ";
//        cout << endl;
    }
    ll res = 0;
    rep(i, 0, n + 1) res = max(res, dp[i]);
    cout << res << endl;
}
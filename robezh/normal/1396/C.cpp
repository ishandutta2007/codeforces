#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6 + 50;
const ll INF = (ll)1e18;
 
int n, r1, r2, r3, d;
ll a[N];
ll psum[N];
ll sum_as = 0;
ll dp[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> r1 >> r2 >> r3 >> d;
    rep(i, 1, n + 1) {
        cin >> a[i];
        ll pb = min(1LL * a[i] * r1 + 2 * r1, 1LL * r1 + r2);
        ll pa = min(1LL * a[i] * r1 + r3, pb + 2 * d);

        psum[i] = psum[i - 1] + pa - pb;
        sum_as += pa;
//        cout << i << ": " << pa - pb << endl;
    }
    sum_as += 1LL * (n - 1) * d;
//    cout << sum_as << endl;
    ll mxprof = -INF;
    rep(i, 1, n + 1) {
        dp[i] = max(dp[i - 1], mxprof + psum[i] - 1LL * 2 * i * d);
        mxprof = max(mxprof, dp[i - 1] - psum[i - 1] + 1LL * 2 * i * d);
    }
    ll mxres = dp[n];
    mxprof = -INF;
    for(int i = n - 2; i >= 0; i--) {
        mxprof = max(mxprof, psum[n - 1] - psum[i] - 1LL * (n - i - 1) * d);
        mxres = max(mxres, dp[i] + mxprof);
    }
    cout << sum_as - mxres << '\n';
 
}
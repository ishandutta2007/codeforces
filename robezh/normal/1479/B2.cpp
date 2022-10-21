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

const int N = (int)1e5 + 50;

int n, a[N];
int dp[N], la[N];
int psum[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 2, n + 1) {
        psum[i] = psum[i - 1] + (a[i] == a[i - 1]);
    }

    int mx = 0;
    dp[0] = 0;
    la[a[1]] = 1;
    rep(i, 1, n) {

        dp[i] = mx;
        int l = la[a[i + 1]];
        dp[i] = max(dp[i], dp[l] + (psum[i] - psum[l + 1]) + (l != 0));

        la[a[i + 1]] = i + 1;

        mx += (a[i] == a[i + 1]);
        mx = max(mx, dp[i]);
//        cout << i << " " << dp[i] << endl;
    }
    cout << n - mx << '\n';


}
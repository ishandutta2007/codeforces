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
const int N = 75, INF = (int)1e9;
int n;
int dp[N][N];

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, N) rep(j, 0, N) dp[i][j] = INF;
        int mx = 1;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                dp[i][j] = 2;
                for(int l = 0; l < i; l++) {
                    // (a[i] - a[l]) / (i - l) == (a[j] - a[i]) / (j - i)
                    if((a[i] - a[l]) * (j - i) == (a[j] - a[i]) * (i - l)) {
                        dp[i][j] = max(dp[i][j], dp[l][i] + 1);
                    }
                }
                mx = max(dp[i][j], mx);
            }
        }
        cout << n - mx << '\n';
    }

}
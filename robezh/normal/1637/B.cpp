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
const int N = 105;

int n;
int a[N];
int c[N][N];
int dp[N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) {
            set<int> S;
            int cur = 0;
            rep(j, i, n) {
                S.insert(a[i]);
                while(S.find(cur) != S.end()) cur++;
                c[i][j] = cur + 1;

            }
        }
        ll res = 0;
        rep(i, 0, n) {
            rep(j, i, n) {
                dp[i][j] = c[i][j];
                for (int k = i + 1; k <= j; k++) dp[i][j] = max(dp[i][k - 1] + c[k][j], dp[i][j]);
                res += dp[i][j];
            }
        }
        cout << res << '\n';

    }


}
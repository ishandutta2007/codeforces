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

const int N = (int)1e6 + 50, LOGN = 20, INF = (int)1e9;

int n;
int p[N];
int dp[N][2];
int la[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {

        cin >> n;
        rep(i, 1, n + 1) cin >> p[i];
        dp[1][0] = -INF;
        dp[1][1] = -INF;
        rep(i, 2, n + 1) {
            dp[i][0] = dp[i][1] = INF;
            rep(j, 0, 2) {
                int b = (j ? -p[i] : p[i]);
                rep(k, 0, 2) {
                    int a = (k ? -p[i - 1] : p[i - 1]);
                    if(a < b) {
                        if(dp[i - 1][k] < dp[i][j]) {
//                            neg[i][j] = j;
                            la[i][j] = k;
                            dp[i][j] = dp[i - 1][k];
                        }
                    }
                    if(dp[i - 1][k] < b) {
                        if(a < dp[i][j]) {
                            dp[i][j] = a;
                            la[i][j] = k;
//                            neg[i][j] = j;
                        }
                    }
                }
            }
        }
//        cout << dp[n][0] << " " << dp[n][1] << endl;
        if(dp[n][0] == INF && dp[n][1] == INF) {
            cout << "NO\n";
        } else {
            int c = (dp[n][0] == INF ? 1 : 0);
            vi res;
            for (int i = n; i >= 1; i--) {
                res.push_back(c ? -p[i] : p[i]);
                c = la[i][c];
            }
            reverse(all(res));
            cout << "YES\n";
            for (int x : res) cout << x << " ";
            cout << '\n';
        }
    }


}
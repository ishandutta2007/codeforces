#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;
const ll INF = (ll)1e18;

int n;
string str;
int s[N];
ll a[N];
int cnt[2][N];
ll dp[2][N][N][N];
ll ans[N][N];

void updmax(ll &to, ll from) {
    to = max(to, from);
}

int main() {
    cin >> n;
    cin >> str;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = str[i - 1] - '0';
        cnt[s[i]][i] = 1;
        cnt[0][i] += cnt[0][i-1];
        cnt[1][i] += cnt[1][i-1];
    }
    for(int l = 0; l <= n + 1; l++) {
        for(int r = 0; r <= n + 1; r++) {
            for(int ct = 0; ct <= n + 1; ct++) {
                if(l > r) ans[l][r] = 0;
                else ans[l][r] = -INF;

                for(int d = 0; d < 2; d++) {
                    if(l > r && ct == 0) dp[d][l][r][ct] = 0;
                    else dp[d][l][r][ct] = -INF;
                }
            }
        }
    }
    for(int dt = 0; dt < n; dt++) {
        for(int l = 1; l + dt <= n; l++) {
            int r = l + dt;
            for(int ct = 1; ct <= r - l + 1; ct++) {
                for(int md = l; md <= r; md ++) {
                    updmax(dp[s[md]][l][r][ct], ans[l][md-1] + dp[s[md]][md+1][r][ct-1]);
                }
                updmax(ans[l][r], a[ct] + dp[0][l][r][ct]);
                updmax(ans[l][r], a[ct] + dp[1][l][r][ct]);
            }
            updmax(dp[0][l][r][0], ans[l][r]);
            updmax(dp[1][l][r][0], ans[l][r]);
        }
    }
//    for(int i = 1; i + 1 <= n; i++) cout << ans[i][i+1] << " ";
//    cout << endl;
    cout << ans[1][n] << endl;
}
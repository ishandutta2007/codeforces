#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 3005;
const int INF = (int)1e9;

int n;
int a[N];
int bad[N][N];
int dp[N][N], sdp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];

        for(int r = 1; r < n; r++) {
            bad[r - 1][r] = 0;
            for(int l = r - 2; l >= 0; l--) bad[l][r] = bad[l + 1][r] + (l + 1 + a[l + 1] >= r);
        }

        for(int l = n - 1; l >= 0; l--) {
            sdp[l][n] = INF;
            for(int r = n - 1; r >= l + 1; r--) {
                if(l + a[l] >= r) {
                    if(r == n - 1) dp[l][r] = bad[l][r];
                    else dp[l][r] = sdp[r][l + a[l] + 1] + bad[l][r];
                } else {
                    dp[l][r] = INF;
                }
//                cout << l << " " << r << ": " << dp[l][r] << endl;
                sdp[l][r] = min(dp[l][r], sdp[l][r + 1]);
            }
        }
        cout << sdp[0][1] << '\n';
    }

}
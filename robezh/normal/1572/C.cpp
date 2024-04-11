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
const int N = (int)3e3 + 50;

int n, a[N];
vi pos[N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) pos[i].clear();
        rep(i, 0, n) {
            cin >> a[i]; a[i]--;
            pos[a[i]].push_back(i);
        }
        rep(len, 1, n + 1) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if(l == r) {
                    dp[l][r] = 0;
                    continue;;
                }
                dp[l][r] = dp[l + 1][r] + 1;
                for (int k : pos[a[l]]) {
                    if(l < k && k <= r) {
                        dp[l][r] = min(dp[l][r], (l + 1 == k ? 0 : dp[l + 1][k - 1] + 1) + dp[k][r]);
                    }
                }
            }
        }
        cout << dp[0][n - 1] << '\n';
    }

}
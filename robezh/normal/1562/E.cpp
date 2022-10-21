#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 5005;

int n;
string str;
int lcp[N][N], dp[N][N], sdp[N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> str;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(str[i] == str[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
                else lcp[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) dp[0][i] = i + 1;
        int res = n;
        for(int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) dp[i][j] = j - i + 1;

            for(int j = 0; j < i; j++) {
                int l = lcp[j][i];
                if(i + l == n) {
                } else if(str[j + l] < str[i + l]) {
                    dp[i][i + l] = max(dp[i][i + l], dp[j][n - 1] + 1);
                } else {
//                    dp[i][i + l] = max(dp[i][i + l], dp[j][j + l - 1] + 1);
                }
            }
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            }
            res = max(res, dp[i][n - 1]);
        }
        cout << res << '\n';
    }

}
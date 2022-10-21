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
const int N = 10005;

typedef long long ll;
int n, m;
string s, t;
int dp[N][N], to[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    n = s.length(), m = t.length();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        to[i] = -1;
        for(int j = i; j < n; j++) {
            sum += (s[j] != '.' ? 1 : -1);
            if(sum < 0) break;
            if(sum == 0) {
                to[i] = j + 1;
                break;
            }
        }
//        cout << i << " to " << to[i] << endl;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[n][m] = 0;
    for(int i = n; i >= 0; i--) {
        for(int j = m; j >= 0; j--) {
            if(i < n && j < m && s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            if(i < n) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            if(to[i] != -1) dp[i][j] = min(dp[i][j], dp[to[i]][j]);
        }
    }
    cout << dp[0][0] << '\n';
}
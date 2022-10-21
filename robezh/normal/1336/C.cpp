#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;

const ll mod = 998244353;
const int N = 3005;

int n, m;
string s, t;
ll dp[N][N], sdp[N][N];
ll pw2[N];

void add(ll &to, ll val) {
    to += val;
    to %= mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = pw2[i-1] * 2 % mod;
    cin >> s;
    cin >> t;
    n = s.length(), m = t.length();
    s = " " + s;
    t = " " + t;

    for(int i = n + 1; i >= 1; i--) {
        add(sdp[i][0], 1);
        for(int j = 0; j <= m; j++) {
            if(j < m && s[i - 1] == t[j + 1]) add(sdp[i - 1][j + 1], sdp[i][j]);
            add(sdp[i - 1][j], sdp[i][j]);
        }
    }

    for(int i = 1; i<= m - 1; i++) dp[i][i] = (t[i] == s[1] ? 2 : 0);
    dp[m][m] = (t[m] == s[1] ? 1 : 0);
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        add(res, (sdp[i][m] - sdp[i + 1][m]) * pw2[i-1] % mod);
    }
    for(int len = 0; len <= m; len++) {
        for(int i = 1; i + len <= m; i++) {
            int j = i + len;
            if(j == m) {
//                cout << i << " " << j << ": " << sdp[len][i - 1] << " " << dp[i][j] << endl;
                add(res, sdp[len + 2][i - 1] * dp[i][j] % mod);
            }
            else {
                if(i > 1 && j != m && s[len + 2] == t[i - 1]) add(dp[i - 1][j], dp[i][j]);
                if(j < m && s[len + 2] == t[j + 1]) add(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[27][27] = {};
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        string s; cin >> s;
        FOR(st, 0, 25) {
            if (dp[st][s[0] - 'a'] != -1) {
                dp[st][s[sz(s) - 1] - 'a'] = max(dp[st][s[sz(s) - 1] - 'a'], dp[st][s[0] - 'a'] + sz(s));
            }
        }
        dp[s[0] - 'a'][s[sz(s) - 1] - 'a'] = max(dp[s[0] - 'a'][s[sz(s) - 1] - 'a'], sz(s));
    }
    int ans = 0;
    FOR(i, 0, 25) ans = max(ans, dp[i][i]);
    cout << ans << endl;
    return 0;
}
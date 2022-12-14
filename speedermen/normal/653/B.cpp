#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

long long dp[10][26];
int cnt[26][26];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    int n, q;
    dp[1][0] = 1;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        string a, b;
        cin >> a >> b;
        cnt[b[0] - 'a'][a[0] - 'a']++;
    }
    for (int i = 1; i <= n; ++i)
        for (int f = 0; f < 26; ++f)
            for (int g = 0; g < 26; ++g)
                dp[i + 1][g] += cnt[f][g] * dp[i][f];
    ll ans = 0;
    for (int i = 0; i < 26; ++i)
        ans += dp[n][i];
    cout << ans;
    return 0;
}
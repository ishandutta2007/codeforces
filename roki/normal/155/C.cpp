#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

string s;
int k;
bool pr[26][26];

bool read()
{
    if (!(cin >> s))
        return false;
    cin >> k;
    forn (i, k)
    {
        char a, b;
        cin >> a >> b;
        pr[a - 'a'][b - 'a'] = true;
        pr[b - 'a'][a - 'a'] = true;
    }
    return true;
}

int dp[100001][26];

void solve()
{
    forn (i, 100000)
        forn (j, 26)
            dp[i + 1][j] = -1;
    int n = s.size();
    int ans = 0;
    forn (i, n)
    {
        forn (j, 26)
        {
            if (!pr[j][s[i] - 'a'])
                dp[i + 1][s[i] - 'a'] = max(dp[i + 1][s[i] - 'a'], dp[i][j] + 1);
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    forn (i, 26)
        ans = max(ans, dp[n][i]);
    cout << n - ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}
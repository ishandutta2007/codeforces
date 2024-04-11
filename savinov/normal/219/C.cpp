#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define out(x) cout << (x);


typedef long double ld;
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }



// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;
char TEMPORARY_CHAR;
// Types
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 1e7;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-'))
    {}
    char neg = 0;
    if (TEMPORARY_CHAR == '-')
    {
        neg = 1;
        TEMPORARY_CHAR = getchar();
    }

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }

    if (neg)
        a = -a;
}
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    in(n);in(k);
    string s;
    cin >> s;
    int dp[26];
    int min1[26],min2[26];
    forn(i,k)
        dp[i] = 1;
    dp[s[0]-'A'] = 0;
    int p[500000][26];
    For(r,1,n-1)
    {
        forn(i,k)
        {
            if (!i)
                min1[0] = 0;
            else
            {
                min1[i] = min1[i-1];
                if (dp[min1[i]]>dp[i])
                    min1[i] = i;
            }
        }
        ford(i,k)
        {
            if (i==k-1)
                min2[k-1] = k-1;
            else
            {
                min2[i] = min2[i+1];
                if (dp[min2[i]]>dp[i])
                    min2[i] = i;
            }
        }
        int dp1[26];
        forn(i,k)
        {
            dp1[i] = INF;
            if (i && dp1[i] > dp[min1[i-1]])
            {
                dp1[i] = dp[min1[i-1]];
                p[r][i] = min1[i-1];
            }
            if (i<k-1 && dp1[i] > dp[min2[i+1]])
            {

                dp1[i] = dp[min2[i+1]];
                p[r][i] = min2[i+1];
            }
        }
        forn(i,k)
        {
            dp[i] = dp1[i] + 1;
            if (i + 'A' == s[r])
                --dp[i];
        }
    }
    vector <char> ans;
    int cur = 0;
    forn(i,k)
        if (dp[i]<dp[cur])
            cur = i;
    cout << dp[cur] << endl;
    ans.pb('A' + cur);
    Ford(r,n-1,1)
    {
        cur = p[r][cur];
        ans.pb('A' + cur);
    }
    reverse(all(ans));
    forn(i,n)
        putchar(ans[i]);
    return 0;
}
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
#include <stack>

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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
typedef long double ld;

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

const int INF = 0x3f3f3f3f;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while ((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0')
    {}

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }
}

#define x first
#define y second

int n(char c)
{
    if (c<='9'&&c>='0') return c-'0';
    if (c<='Z'&&c>='A') return c-'A'+10;
}

int main()
{
    VI ans;
    char c;
    char s1[5];
    char s2[5];
    int i = 0;
    while ((c=getchar())!=':')
    {
        s1[i++] = c;
    }
    int l1 = i;
    i = 0;
    while ((c=getchar())!='\n')
    {
        s2[i++] = c;
    }
    int l2 = i;
    for(int i=2;i<100;i++)
    {
        bool flag = true;
        ll p = 1;
        ll h = 0;
        ford(j,l1)
        {
            if (n(s1[j])>=i) flag = false;
            h+=p*n(s1[j]);
            p*=i;
        }
        if (h>=24) flag = false;
        p = 1;
        ll m = 0;
        ford(j,l2)
        {
            if (n(s2[j])>=i) flag = false;
            m+=p*n(s2[j]);
            p*=i;
        }
        if (m>=60) flag = false;
        if (flag) ans.pb(i);
        if (flag&&i==99)
        {
            cout << "-1";
            return 0;
        }
    }
    if ((int)ans.size()==0)
    {
        cout <<"0" << endl;
        return 0;
    }
    fori(it,ans) cout << *it << " ";
    return 0;
}
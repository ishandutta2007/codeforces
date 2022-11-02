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

int main()
{
    in(n);
    PII a[100001];
    forn (i,n)
    {
        input(a[i].x);
        a[i].y = i+1;
    }
    sort(a,a+n);
    int s1 = 0;
    int s2 = 0;
    int ma = a[n-1].x;
    vector <int> a1,a2;
    int st = 1;
    ford(i,n)
    {
        if (st)
        {
            a1.pb(a[i].y);
            s1+=a[i].x;
        }
        else
        {
            a2.pb(a[i].y);
            s2+=a[i].x;
        }
        st^=1;
    }
    if (s1>s2+ma)
    {
        a1.pop_back();
        a2.pb(a[0].y);
    }
    cout << (int)a1.size() << endl;
    fori(it,a1)
        cout << *it << " ";
    cout << endl;
    cout << (int)a2.size() << endl;
    fori(it,a2)
        cout << *it << " ";
    cout << endl;
    return 0;
}
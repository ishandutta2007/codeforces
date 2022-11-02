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

const ll p = 1003001;

ll has (VI &a)
{
    ll ans = 0;
    fori(it,a)
    {
        ans = ans*p+(ll)(*it);
    }
    return ans;
}

int main()
{
    in(n);
    in(m);
    VVI g(n);
    forn(i,m)
    {
        in(a);
        in(b);
        g[a-1].pb(b);
        g[b-1].pb(a);
    }
    vector <ll> h(n);
    forn(i,n)
    {
        sort(all(g[i]));
        h[i]=has(g[i]);
    }
    sort(all(h));
    ll ans = 0;
    forn(i,n)
    {
        int cnt = 0;
        while (i+cnt<n&&h[i]==h[i+cnt]) cnt++;
        i = i + cnt - 1;
        ans += ((ll)cnt*(ll)(cnt-1))>>1;
    }
    forn(i,n)
    {
        g[i].pb(i+1);
        sort(all(g[i]));
        h[i]=has(g[i]);
    }
    sort(all(h));
    forn(i,n)
    {
        int cnt = 0;
        while (i+cnt<n&&h[i]==h[i+cnt]) cnt++;
        i = i + cnt - 1;
        ans += ((ll)cnt*(ll)(cnt-1))>>1;
    }
    cout << ans;
    return 0;

}
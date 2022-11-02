#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unordered_map>
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
typedef unordered_map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 1e9;

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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    in(k);in(b);in(n);
    int a[n];
    forn(i,n)
        a[i] = nxt();
    ll zero = 0;
    ll ans = 0;
    int r = 0;
    while (r<n)
    {
        ll cnt = 0;
        while (r+cnt<n && a[r+cnt] == 0)
            cnt++;
        zero += ((cnt+1)*cnt) >> 1ll;
        if (a[r])
            cnt ++;
        r += cnt;
    }
    int l = k - 1;
    unordered_map <int, int> mp;
    int s = 0;
    mp[0] = 1;
    forn(i,n)
    {
        s = (s + a[i]) % l;
        int from = (s - b + l) % l;
        ans += mp[from];
        ++mp[s];
    }
    if (!b)
        cout << zero;
    else
        if (b == l)
            cout << ans - zero;
        else
            cout << ans;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
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
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-8;
char TEMPORARY_CHAR;
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;
const ll INF = 1e17;
const int N = 1 << 17;
inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){}
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

#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)

#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

map <PII, int> r;

int f(int a, int cnt)
{
    if (!a || cnt < 0)
        return 0;
    if (r.count(mp(a, cnt)))
        return r[mp(a, cnt)];
    if (a <= 10)
    {
        if (cnt > 1)
            return r[mp(a, cnt)] = 0;
        int rr = (a >= 4) + (a >= 7);
        if (cnt)
            return r[mp(a, cnt)] = rr;
        else
            return r[mp(a, cnt)] = a - rr;
    }
    int b = a;
    int p = 1;
    while (b >= 10)
    {
        p *= 10;
        b /= 10;
    }
    int d = a / p;
    //cout << a << " " << d << endl;
    if (d == 4 || d == 7)
        return r[mp(a, cnt)] = f(d * p - 1, cnt) + f(a % p, cnt - 1) + (cnt == 1);
    else
        return r[mp(a, cnt)] = f(d * p - 1, cnt) + f(a % p, cnt) + (cnt == 0);
}

ll calc(int a, int b, VI from)
{
    ll ans = 0;
    if (!b)
    {
        if (!a)
            return 1;
        else
            return 0;
    }
    forn(i, a + 1)
        if (from[i])
        {
            from[i]--;
            ans += (from[i] + 1) * calc(a - i, b - 1, from);
            ans %= 1000000007;
            from[i]++;
        }
    return ans;
}
int main()
{
    in(m);
    //cout << f (m, 9);
    VI k(10);
    ford(i, 10)
    {
        k[i] = f(m, i);
        //cout << k[i] << endl;
    }
    ll ans = 0, sum = 0;
    forn(i, 10)
    {
        ans = (ans + k[i] * sum) % 1000000007;
        sum = (sum + calc(i, 6, k)) % 1000000007;
    }
    cout << ans << endl;
    return 0;
}
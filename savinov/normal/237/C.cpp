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

const ll INF = 1e17;

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
const int m = 1000000;
int s[m + 1];
int a, b, k;
bool check(int l)
{
    bool ret = true;
    for(int i = a; i <= b - l + 1; ++i)
        ret &= (s[i + l - 1] - s[i - 1] >= k);
    return ret;
}

int main()
{
    bool prime[m + 1];
    clr(prime);
    for(int i = 2; i * i <= m; ++i)
        if (!prime[i])
            for(int j = i * i; j <= m; j += i)
                prime[j] = true;
    prime[0] = true;
    prime[1] = true;
    s[0] = 0;
    For(i, 1, m)
        s[i] = s[i - 1] + (!prime[i]);
    a = nxt();
    b = nxt();
    k = nxt();
    int l = 1, r = b - a + 2;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m  + 1;
    }
    if (l <= b - a + 1)
        cout << l << endl;
    else
        cout << "-1" << endl;
    return 0;
}
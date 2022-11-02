#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 4e-5; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 2e9;inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} template <class _T> inline void print(const _T & a, ostream & os = cout){for(auto z : a) os << z << " "; os << endl;}

clock_t tm0;

double cur_time()
{
    return (clock() - tm0) / (double)CLOCKS_PER_SEC;
}

int MOD = 1000000007;


PII check(vector <PII> &a)
{
    sort(all(a));
    PII ret;
    ret.x = a[0].x;
    forn(i, a.size() - 1)
    {
        if (a[i].y != a[i + 1].x)
        {
            puts("NO");
            exit(0);
        }
    }
    ret.y = a.back().y;
    return ret;
}

int main()
{
    in(n);
    vector <PII> y[40000];
    forn(i, n)
    {
        in(x1); in(y1);
        in(x2); in(y2);
        for(int x = x1; x < x2; ++x)
        {
            y[x].pb(mp(y1, y2));
        }
    }
    int f = 0;
    int cnt = 0;
    PII cur;
    for(int x = 0; x < 32000; ++x)
    {
        if (f == 2 && !y[x].empty())
        {
            puts("NO");
            return 0;
        }
        if (f == 2) continue;
        if (f == 1)
        {
            if (y[x].empty())
            {
                f = 2;
                continue;
            }
            cnt++;
            PII z = check(y[x]);
            if (z != cur)
            {
                puts("NO");
                return 0;
            }
        }
        else
        {
            if (!y[x].empty())
            {
                f = 1;
                cnt++;
                cur = check(y[x]);
            }
        }
    }
    if (cnt == cur.y - cur.x)
        puts("YES");
    else
        puts("NO");
    return 0;
}
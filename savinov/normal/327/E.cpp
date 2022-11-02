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
//#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
//#include <unordered_set>
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
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 4e-5; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 2e9;inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} //template <class _T> inline void print(const _T & a, ostream & os = cout){for(auto z : a) os << z << " "; os << endl;}

int mod = 1000000007;

int main()
{
    in(n);
    int M = 1 << n;
    int * s = new int[M];
    s[0] = 0;
    forn(i, n)
        s[1 << i] = nxt();
    forn(i, M)
    {
        if (!i) continue;
        int pr = i & (-i);
        s[i] = s[pr] + s[i ^ pr];
        if (s[i] >= mod) s[i] = mod;
    }
    in(k);
    ll b[k];
    forn(i, k)
        b[i] = nxt();
    s[0] = 1;
    forn(i, M)
    {
        if (!i) continue;
        bool fl = true;
        forn(j, k)
            if (s[i] == b[j])
            {
                s[i] = 0;
                fl = false;
            }
        if (fl)
        {
            int ans = 0;
            forn(j, n)
                if ((i >> j) & 1)
                {
                    ans += s[i ^ (1 << j)];
                    if (ans >= mod) ans -= mod;
                }
            s[i] = ans;
        }
    }
    cout << s[M - 1] << endl;
    return 0;
}
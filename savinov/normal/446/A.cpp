#ifdef LOCAL
    #include <iostream>
    #include <cstring>
    #include <cmath>
    #include <vector>
    #include <set>
    #include <map>
    #include <cstdio>
    #include <cmath>
    #include <iomanip>
    #include <sstream>
    #include <cassert>
#else
    #include <bits/stdc++.h>
#endif

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
 
using namespace std;
 
template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    in(n);

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    int d1[n], d2[n];

    d1[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            d1[i] = d1[i - 1] + 1;
        } else {
            d1[i] = 1;
        }
    }

    d2[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) {
            d2[i] = d2[i + 1] + 1;
        } else {
            d2[i] = 1;
        }
    }

    int ans = 1;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ans = max(ans, d1[i - 1] + 1);
        }
        if (i < n - 1) {
            ans = max(ans, d2[i + 1] + 1);
        }
        if (i > 0 && i < n - 1 && a[i + 1] - a[i - 1] > 1) {
            ans = max(ans, d1[i - 1] + d2[i + 1] + 1);
        }
    }

    cout << ans << endl;

    return 0;
}
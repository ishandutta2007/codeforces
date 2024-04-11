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

const int MAXN = 300000;

long long powers[MAXN + 1];

struct data {
    int len;
    long long data1;
    long long data2;
};

data merge(const data & l, const data & r) {
    data res;
    res.len = l.len + r.len;
    res.data1 = r.data1 + l.data1 * powers[r.len];
    res.data2 = l.data2 + r.data2 * powers[l.len];
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    in(n);

    int x[n];

    powers[0] = 1;

    for (int i = 1; i <= n; ++i) {
        powers[i] = powers[i - 1] * 3;
    }

    for (int i = 0; i < n; ++i) {
        x[i] = nxt() - 1;
    }

    data t[n + n];

    for (int i = 0; i < n; ++i) {
        t[i + n].len = 1;
        t[i + n].data1 = t[i + n].data2 = 0;
    }

    for (int i = n - 1; i > 0; --i) {
        t[i] = merge(t[i + i], t[i + i + 1]);
    }

    for (int i = 0; i < n; ++i) {
        t[x[i] + n].data1 = t[x[i] + n].data2 = 1;
        int pos = x[i] + n;
        for (pos >>= 1; pos; pos >>= 1) {
            t[pos] = merge(t[pos + pos], t[pos + pos + 1]);
        }
        int r = min(x[i], n - x[i] - 1);
        data L{0, 0, 0};
        data R{0, 0, 0};
        int a = x[i] - r, b = x[i] + r;
        for (a += n, b += n; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
            if (a & 1) {
                L = merge(L, t[a]);
            }
            if (!(b & 1)) {
                R = merge(t[b], R);
            }
        }
        data res = merge(L, R);
        if (res.data1 != res.data2) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
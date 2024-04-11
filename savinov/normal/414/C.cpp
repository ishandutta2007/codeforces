#include <bits/stdc++.h>
#include <ext/rope>
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
T gcd(T a, T b)
{
    while (b > 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(ll a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

#define count cosjkdfjsdkf

long long count[50][2];

int a[1 << 20];

void merge(int l1, int r1, int l2, int r2, int level) {
    int tmp[2 * (r1 - l1)];
    int k = 0;

    int r = l2;
    for (int i = l1; i < r1; ++i) {
        while (r < r2 && a[r] < a[i]) {
            ++r;
        }
        count[level][0] += r - l2;
    }

    r = l1;
    for (int i = l2; i < r2; ++i) {
        while (r < r1 && a[r] < a[i]) {
            ++r;
        }
        count[level][1] += r - l1;
    }
    int i, j;
    for (i = l1, j = l2; i < r1 && j < r2; ) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while(i < r1) {
        tmp[k++] = a[i++];
    }
    while (j < r2) {
        tmp[k++] = a[j++];
    }
    memcpy(a + l1, tmp, sizeof(tmp));
}

void sort(int l, int r, int level) {
    if (r - l == 1)
        return;
    int mid = (l + r) / 2;
    sort(l, mid, level + 1);
    sort(mid, r, level + 1);
    merge(l, mid, mid, r, level);
}

int main() {
    clr(count);
    in(n);

    for (int i = 0; i < (1 << n); ++i) {
        a[i] = nxt();
    }
    sort(0, (1 << n), 0);
    in(m);
    while (m--) {
        in(q);
        q = n - q;
        for (int i = q; i <= n; ++i)
            swap(count[i][0], count[i][1]);
        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans += count[i][0];
        }
        out(ans);
        puts("");
    }

    return 0;
}
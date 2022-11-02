#include <bits/stdc++.h>

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


typedef unsigned int T;
const int N = 200000;
const int B = sizeof(T) * 8;
const int S = 31 - __builtin_clz(B);

T a[B][(N + B - 1) / B];
T b[B][(N + B - 1) / B];

char s1[N + 1];
char s2[N + 1];

static __inline int popcnt(T n)
{
    int ret;
#ifdef __GNUC__
    __asm__("popcnt %0, %1" : "=r"(ret) : "r"(n));
#else
    __asm { popcnt ret, n; }
#endif
    return ret;
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("brilliant.in", "r", stdin);
    //freopen("brilliant.out", "w", stdout);
#endif

    gets(s1);
    gets(s2);

    int n1 = strlen(s1);
    int n2 = strlen(s2);

//    for (int i = 0; i < n1; ++i) {
//        s1[i] = rand() % 2 + '0';
//    }
//    for (int i = 0; i < n2; ++i) {
//        s2[i] = rand() % 2 + '0';
//    }


    for (int i = 0; i < n1; ++i) {
        if (s1[i] == '1') {
            for (int j = 0; j < B; ++j) {
                if (i >= j) {
                    a[j][(i - j) >> S] |= T(1) << ((i - j) & (B - 1));
                }
            }
        }
    }

    for (int i = 0; i < n2; ++i) {
        if (s2[i] == '1') {
            for (int j = 0; j < B; ++j) {
                if (i >= j) {
                    b[j][(i - j) >> S] |= T(1) << ((i - j) & (B - 1));
                }
            }
        }
    }

    in(q);
    //int q = 400000;

    while (q--) {
        in(p1);
        in(p2);
        in(len);
//        int len = n1;//rand() % min(n1, n2) + 1;
//        int p1 = 0;//rand() % (n1 - len + 1);
//        int p2 = 0;//rand() % (n2 - len + 1);

        int x1 = p1 & (B - 1);
        int x2 = p2 & (B - 1);

        int y1 = p1 >> S;
        int y2 = p2 >> S;

        int cnt = len >> S;
        int rem = len & (B - 1);

        T * aa = a[x1] + y1;
        T * bb = b[x2] + y2;

        int ans = 0;

        for (; cnt--; ++aa, ++bb) {
            ans += popcnt(*aa ^ *bb);
        }

        ans += popcnt((*aa ^ *bb) & ((T(1) << rem) - 1));

        out(ans);
        puts("");
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
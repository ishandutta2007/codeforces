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

//#define double ld

long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1 ;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //freopen("hot.in", "r", stdin);
    //freopen("hot.out", "w", stdout);
#endif
    
    string s;
    cin >> s;

    int n;
    cin >> n;

    string t[n];

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int val[n + 1][10];
    int len[n + 1][10];
    for (int i = 0; i < 10; ++i) {
        val[n][i] = i;
        len[n][i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        int d = t[i][0] - '0';
        string z = t[i].substr(3);
        for (int j = 0; j < 10; ++j) {
            if (j != d) {
                val[i][j] = val[i + 1][j];
                len[i][j] = len[i + 1][j];
            }
        }
        long long res = 0;
        long long l = 0;
        for (int j = 0; j < (int)z.length(); ++j) {
            res = (res * pw(10, len[i + 1][z[j] - '0']) + val[i + 1][z[j] - '0']) % mod;
            l = (l + len[i + 1][z[j] - '0']) % (mod - 1);
        }
        val[i][d] = res;
        len[i][d] = l;
    }
    long long res = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        res = (res * pw(10, len[0][s[i] - '0']) + val[0][s[i] - '0']) % mod;
    }
    cout << res << endl;
#ifdef LOCAL
    cout << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}
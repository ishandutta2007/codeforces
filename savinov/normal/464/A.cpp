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

int main() {
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //freopen("hot.in", "r", stdin);
    //freopen("hot.out", "w", stdout);
#endif
    in(n); in(m);

    if (m == 1) {
        cout << "NO" << endl;
        return 0;
    }

    string s;
    cin >> s;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = s[i] - 'a' + 1; j < m; ++j) {
            if (i > 0 && s[i - 1] == 'a' + j) continue;
            if (i > 1 && s[i - 2] == 'a' + j) continue;
            string t = s;
            t[i] = 'a' + j;
            char ok = true;
            for (int k = i + 1; k < n; ++k) {
                for (t[k] = 'a'; t[k] < 'a' + m; ++t[k]) {
                    if (k > 0 && t[k] == t[k - 1]) continue;
                    if (k > 1 && t[k] == t[k - 2]) continue;
                    goto l1;
                }
                ok = false;
                break;
                l1:;
            }
            if (ok) {
                cout << t << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    

#ifdef LOCAL
    cout << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}
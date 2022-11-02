#include <bits/stdc++.h>
#include <ext/rope>
#pragma GCC optimize ("O3")
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

using namespace __gnu_cxx;

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
    freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
#else
    //freopen("trie.in", "r", stdin);
    //freopen("trie.out", "w", stdout);
#endif
    in(n); in(m); in(k); in(w);

    char data[k][n][m + 1];

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            gets(data[i][j]);
        }
    }

    int d[k + 1][k + 1];
    clr(d);

    for (int i = 0; i < k; ++i) {
        d[0][i + 1] = d[i + 1][0] = n * m;
        for (int j = i + 1; j < k; ++j) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    d[i + 1][j + 1] += (int)(data[i][x][y] != data[j][x][y]);
                    d[j + 1][i + 1] += (int)(data[i][x][y] != data[j][x][y]);
                }
            }
            d[i + 1][j + 1] *= w;
            d[j + 1][i + 1] *= w;
        }
    }

    vector <char> used(k + 1);
    vector<int> min_e (k + 1, INF), sel_e (k + 1, -1);
    min_e[0] = 0;

    int sum = 0;
    vector <int> q;
    for (int i=0; i<=k; ++i) {

        int v = -1;
        for (int j=0; j<=k; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        sum += min_e[v];
        used[v] = true;
        q.push_back(v);
        for (int to=0; to<=k; ++to)
            if (!used[to] && d[v][to] < min_e[to]) {
                min_e[to] = d[v][to];
                sel_e[to] = v;
            }
    }
    cout << sum << endl;

    for (int i = 1; i <= k; ++i) {
        cout << q[i] << " " << sel_e[q[i]] << "\n";
    }

    return 0;

}
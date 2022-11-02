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

int p[100000];

int sz[100000];

long long sum = 0;

long long sum2 = 0;

int get(int v) {
    if (v != p[v]) {
        p[v] = get(p[v]);
    }
    return p[v];
}

void unite(int a, int b, long long cost) {
    a = get(a);
    b = get(b);
    if (a == b) {
        return;
    }
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    p[a] = b;
    sum += (long long) sz[a] * sz[b] * cost;
    sum2 += (long long) sz[a] * sz[b];
    sz[b] += sz[a];

}

int main()
{
#ifdef LOCAL
    freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
#else
    //freopen("trie.in", "r", stdin);
    //freopen("trie.out", "w", stdout);
#endif
    in(n);
    in(m);
    PII cost[n];
    int co[n];
    for (int i = 0; i < n; ++i) {
        co[i] = nxt();
        cost[i] = mp(co[i], i);
        p[i] = i;
        sz[i] = 1;
    }
    sort(cost, cost + n, greater<PII>());

    vector <int> g[n];
    for (int i = 0; i < m; ++i) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    char used[n];
    clr(used);
    for (int i = 0; i < n; ++i) {
        int v = cost[i].y;
        vector <int> d;
        for (int to : g[v]) {
            if (used[to]) {
                unite(v, to, co[v]);
            }
        }
        used[v] = 1;
    }
    cout << setprecision(10) << fixed;
    cout << 2 * (double)sum / n / (n - 1) << endl;
    return 0;
}
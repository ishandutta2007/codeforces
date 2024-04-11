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

char field[2001][2001];

int R[2001][2001];

int L[2001][2001];

int U[2001][2001];

int n, m, k;

int getR(int x, int y) {
    if (x >= n || y < 0) {
        return 0;
    }
    if (R[x][y] != -1) {
        return R[x][y];
    }
    //cerr << x << " " << y << " " << (int)(field[x][y] == 'R') + getR(x + 1, y - 1) << endl;
    return R[x][y] = (int)(field[x][y] == 'R') + getR(x + 1, y - 1);
}

int getL(int x, int y) {
    if (x >= n || y >= m) {
        return 0;
    }
    if (L[x][y] != -1) {
        return L[x][y];
    }
    return L[x][y] = (int)(field[x][y] == 'L') + getL(x + 1, y + 1);
}

int getU(int x, int y) {
    if (x >= n) {
        return 0;
    }
    if (U[x][y] != -1) {
        return U[x][y];
    }
    return U[x][y] = (int)(field[x][y] == 'U') + getU(x + 2, y);
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
    input(n); input(m); input(k);

    memset(L, 255, sizeof(L));
    memset(R, 255, sizeof(R));
    memset(U, 255, sizeof(U));

    for (int i = 0; i < n; ++i) {
        gets(field[i]);
        //puts(field[i]);
    }

    for (int j = 0; j < m; ++j) {
        if (j) cout << " ";
        cout << getU(0, j) + getL(0, j) + getR(0, j);
        //cout << getU(0, j) << " " << getL(0, j) << " " << getR(0, j) << endl;
    }
    cout << endl;

    return 0;

}
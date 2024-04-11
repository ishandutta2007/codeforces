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

typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int s[1002][1002];

int sum = 0;

int dx[] = {1, 0};
int dy[] = {0, 1};

int get(int x, int y, int h, int l) {
    return s[x + h][y + l] - s[x][y + l] - s[x + h][y] + s[x][y];
}

bool solve(int h, int l, int x, int y) {
    int nn = h * l;
    if (get(x, y, h, l) != nn) {
        return false;
    }
    //cerr << h << " " << l << endl;
    int sq = h * l;
    while (1) {
        int can = 0;
        for (int i = 0; i < 2; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (get(xx, yy, h, l) == nn) {
                can |= 1 << i;
            }
        }

        if (can == 3) {
            return false;
        }
        if (can == 0) {
            break;
        }
        if (can == 1) {
            sq += l;
            ++x;
        } else {
            sq += h;
            ++y;
        }
    }
    return sq == sum;
}

int main() {
    srand(234134211);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    in(n); in(m);

    string v[n];

    int A = -1, B = -1;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < m; ++j) {
            s[i + 1][j + 1] = v[i][j] == 'X';
            if (v[i][j] == 'X' && A == -1) {
                A = i;
                B = j;
            }
            s[i + 1][j + 1] += s[i][j + 1];
            s[i + 1][j + 1] += s[i + 1][j];
            s[i + 1][j + 1] -= s[i][j];
        }
    }

    sum = s[n][m];

    int h = 0;
    while (A + h < n && v[A + h][B] == 'X') {
        ++h;
    }

    int l = 0;
    while (B + l < m && v[A][B + l] == 'X') {
        ++l;
    }


    int ans = INT_MAX;
    for (int i = 1; i <= h; ++i) {
        if (solve(i, l, A, B)) {
            ans = min(ans, i * l);
        }
    }

    for (int i = 1; i <= l; ++i) {
        if (solve(h, i, A, B)) {
            ans = min(ans, i * h);
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
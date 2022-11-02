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

typedef vector <int> permutation;

const int N = 1000000;

int n;

int res[N];

void apply(int * x, int * p) {
    for (int i = 0; i < n; ++i) {
        res[p[i]] = x[i];
    }
    memcpy(x, res, n * sizeof(int));
}

void multiply(int * x, int * p) {
    for (int i = 0; i < n; ++i) {
        res[i] = p[x[i]];
    }
    memcpy(x, res, n * sizeof(int));
}


void apply(int * p, int k, int * x) {
    while (k) {
        if (k & 1) {
            apply(x, p);
        }
        multiply(p, p);
        k >>= 1;
    }
}


char s[1000001];
char t[1000001];

int main() {
    srand(33);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //string filename = "immetric";
    //freopen((filename + ".in").c_str(), "r", stdin);
    //freopen((filename + ".out").c_str(), "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    gets(s);
    n = strlen(s);
    in(q);

    int * shiftLeft = new int[n];
    for (int i = 0; i < n; ++i) {
        shiftLeft[i] = (i - 1 + n) % n;
    }
    int * shiftRight = new int[n];
    for (int i = 0; i < n; ++i) {
        shiftRight[i] = (i + 1) % n;
    }

    int * x = new int[n];
    for (int i = 0; i < n; ++i) {
        x[i] = i;
    }
    int * sort = new int[n];
    while (q--) {
        in(k); in(d);
        for (int i = 0; i < n; ++i) {
            sort[i] = i;
        }
        int sz = 0;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j * d + i < k; ++j) {
                sort[j * d + i] = sz++;
            }
        }
        multiply(sort, shiftLeft);
        apply(sort, n - k + 1, x);
        for (int i = 0, add = n - k + 1; i < n; ++i, ++add) {
            if (add == n) add = 0;
            res[add] = x[i];
        }
        memcpy(x, res, n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            t[i] = s[x[i]];
        }
        puts(t);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
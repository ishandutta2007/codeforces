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

typedef long double ld; typedef unsigned int uint; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

const int K = 60;

struct data {
    long long time[K];

    data(const data & r) {
        memcpy(time, r.time, sizeof(time));
    }
    data() {
        clr(time);
    }
};

data tmp;

void merge(const data &l, const data & r, data & res) {

    for (int i = 0; i < K; ++i) {
        tmp.time[i] = l.time[i] + r.time[(l.time[i] + i) % K];
    }
    for (int i = 0; i < K; ++i) {
        res.time[i] = tmp.time[i];
    }
}

data u[7];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "cheval";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif

    for (int i = 2; i <= 6; ++i) {
        for (int j = 0; j < K; ++j) {
            int t = j;
            while (t % i == 0) {
                ++t;
            }
            u[i].time[j] = t - j + 1;
        }
    }

    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    int N = 1;
    while (N < n) {
        N *= 2;
    }

    data st[N + N];

    for (int i = 0; i < n; ++i) {
        st[i + N] = data(u[a[i]]);
    }

    for (int i = N - 1; i > 0; --i) {
        merge(st[i + i], st[i + i + 1], st[i]);
    }

    int m;
    scanf("%d", &m);
    char s[2];
    while (m--) {
        int x, y;
        scanf("%s%d%d", s, &x, &y);
        if (s[0] == 'A') {
            --x; --y;
            --y;
            data resL, resR;
            clr(resL.time);
            clr(resR.time);
            for (x += N, y += N; x <= y; x = (x + 1) >> 1, y = (y - 1) >> 1) {
                if (x & 1) {
                    merge(resL, st[x], resL);
                }
                if (!(y & 1)) {
                    merge(st[y], resR, resR);
                }
            }
            merge(resL, resR, resL);
            cout << resL.time[0] << "\n";
        } else {
            --x;
            x += N;
            st[x] = data(u[y]);

            for (x >>= 1; x; x >>= 1) {
                merge(st[x + x], st[x + x + 1], st[x]);
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL
    return 0;
}
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

struct T {
    int x;
    long long y;

    bool operator<(const T & r) const {
        return x < r.x;
    }
};

int main() {
    srand(234134211);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    in(n);

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    int logTable[n + 1];
    logTable[0] = 0;
    logTable[1] = 0;
    for (int i = 2; i <= n; i++)
        logTable[i] = logTable[i >> 1] + 1;

    int rmq[logTable[n] + 1][n];

    for (int i = 0; i < n; ++i)
        rmq[0][i] = a[i];

    for (int k = 1; (1 << k) < n; ++k) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            int x = rmq[k - 1][i];
            int y = rmq[k - 1][i + (1 << k - 1)];
            rmq[k][i] = gcd(x, y);
        }
    }


    cerr << "OK" << endl;

    vector <PII> x;

    for (int i = 0; i < n; ++i) {
        int j = i;
        //cerr << "i = " << i << endl;
        while (j < n) {
            int l = j, r = n - 1;
            int k = logTable[j - i];
            int u = rmq[k][i];
            int v = rmq[k][j - (1 << k) + 1];
            int G = gcd(u, v);

            while (l < r) {
                int m = (l + r + 1) >> 1;
                //cerr << l << " " << r << " " << m << endl;
                int k = logTable[m - i];
                int x = rmq[k][i];
                int y = rmq[k][m - (1 << k) + 1];

                int g = gcd(x, y);

                if (g == G) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            x.push_back(mp(G, l - j + 1));
            j = l + 1;
        }
    }


    sort(all(x));

    vector <T> v;

    in(q);

    int b[q];


    for (int i = 0; i < q; ++i) {
        b[i] = nxt();
    }


    for (int i = 0; i < (int)x.size(); ++i) {
        int j = i;
        long long sum = 0;
        while (x[j].x == x[i].x) {
            sum += x[j++].y;
        }
        v.push_back(T{x[i].x, sum});
        i = j - 1;
    }

    for (int i = 0; i < q; ++i) {
        auto it = lower_bound(all(v), T{b[i], 0});
        if (it != v.end() && it->x == b[i]) {
            cout << it->y << "\n";
        } else {
            cout << "0" << "\n";
        }
    }




#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
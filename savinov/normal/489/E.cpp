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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "meeting";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif
    in(n); in(l);
    int x[n + 1];
    int b[n + 1];
    x[0] = b[0] = 0;

    for (int i = 0; i < n; ++i) {
        x[i + 1] = nxt();
        b[i + 1] = nxt();
    }

    double L = 0, R = 1e9;

    while (R - L > 1e-8) {
        double m = (L + R) / 2;

        double dp[n + 1];

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = 1e9;
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + sqrt(fabs(x[i] - x[j] - l)) - m * b[i]);
            }
        }
        if (dp[n] < 0) {
            R = m;
        } else {
            L = m;
        }
    }

    double dp[n + 1];
    int p[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = 1e9;
        for (int j = 0; j < i; ++j) {
            double cost = dp[j] + sqrt(fabs(x[i] - x[j] - l)) - R * b[i];
            if (cost < dp[i]) {
                dp[i] = cost;
                p[i] = j;
            }
        }
    }

    int cur = n;

    vector <int> ans;

    while (cur) {
        ans.push_back(cur);
        cur = p[cur];
    }
    reverse(all(ans));
    //cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL

    return 0;
}
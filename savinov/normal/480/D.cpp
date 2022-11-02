#ifdef LOCAL
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

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

struct data {
    int IN;
    int OUT;
    int W;
    int S;
    int V;

    bool operator<(const data & r) const {
        return IN < r.IN || (IN == r.IN && OUT > r.OUT);
    }
};

data a[501];

int dp[501][1001];
int n;


int solve(int id, int s) {
    int & res = dp[id][s];
    if (res != -1) {
        return res;
    }
    res = a[id].V;
    s = min(s - a[id].W, a[id].S);
    vector <int> ids;
    for (int i = id + 1; i < n; ++i) {
        if (a[i].IN > a[id].OUT) break;
        if (a[i].OUT <= a[id].OUT) {
            ids.pb(i);
        }
    }
    //cerr << id << " " << s << endl;
    //cerr << ids.size() << endl;
    int DP[1000];
    clr(DP);

    for (int i = max(a[id].IN, 0), j = 0; i <= a[id].OUT; ++i) {
        if (i) DP[i] = max(DP[i], DP[i - 1]);
        while (j < (int)ids.size() && a[ids[j]].IN == i) {
            int cur = ids[j];
            if (a[cur].W <= s) DP[a[cur].OUT] = max(DP[a[cur].OUT], DP[i] + solve(cur, s));
            ++j;
        }

    }
    //cerr << id << " " << s << endl;
    return res = res + DP[a[id].OUT];
}

int main() {
    srand(234134211);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //string filename = "two-rectangles";
    //freopen((filename + ".in").c_str(), "r", stdin);
    //freopen((filename + ".out").c_str(), "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    input(n);
    in(s);

    a[0].IN = -1;
    a[0].OUT = 999;
    a[0].W = 0;
    a[0].S = s;
    a[0].V = 0;
    for (int i = 1; i <= n; ++i) {
        a[i].IN = nxt();
        a[i].OUT = nxt();
        a[i].W = nxt();
        a[i].S = nxt();
        a[i].V = nxt();
    }
    ++n;
    sort(a, a + n);

    memset(dp, 255, sizeof(dp));

    cout << solve(0, s) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
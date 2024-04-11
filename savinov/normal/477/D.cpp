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


string convert(int a) {
    string res;
    //cerr << "CONVERT " << a << " ";
    while (a) {
        res = res + (char)(a % 2 + '0');
        a >>= 1;
    }

    reverse(all(res));
    //cerr << res << endl;
    return res;
}

string add(const string & a, const string & b) {
    string res = string(max(a.length(), b.length()) + 1, '0');
    int o = 0;
    for (int i = 0; i < res.length(); ++i) {
        if (i < a.length()) {
            o += a[a.length() - 1 - i] - '0';
        }
        if (i < b.length()) {
            o += b[b.length() - 1 - i] - '0';
        }
        res[res.length() - 1 - i] = o % 2 + '0';
        o >>= 1;
    }
    if (res[0] == '0') {
        return res.substr(1);
    }
    return res;
}

string & MIN( string & a,  string & b) {
    if (a.length() > b.length()) {
        return b;
    }
    if (b.length() > a.length()) {
        return a;
    }
    return a < b ? a : b;
}


int ways[5000][5000 + 1];
int mi[5000][5000 + 1];
int lcp[5000][5000];

int main() {
    srand(234134211);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //string filename = "circles";
    //freopen((filename + ".in").c_str(), "r", stdin);
    //freopen((filename + ".out").c_str(), "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    int n = (int)s.length();

    for (int i = 0; i < n; ++i) {
        string t = s.substr(i) + "#" + s;
        int z[t.length()];
        int m = (int)t.length();
        int l = 0, r = 0;
        for (int j = 1; j < m; ++j) {
            if (j <= r) {
                z[j] = min(r - j + 1, z[j - l]);
            } else {
                z[j] = 0;
            }
            while (j + z[j] < m && t[j + z[j]] == t[z[j]]) {
                ++z[j];
            }
            if (j+z[j]-1 > r)
                l = j,  r = j+z[j]-1;
        }
        for (int j = 0; j < n; ++j) {
            lcp[i][n - 1 - j] = z[m - 1 - j];
        }
    }
    cerr << clock() << endl;
    cerr << "LCPS ARE READY" << endl;

    memset(mi, 0x3f, sizeof(mi));

    int mod = 1000000007;

    ways[0][0] = 1;
    mi[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        for (int j = i; j < n; ++j) {
            ways[i][j + 1] += ways[i][j];
            if (ways[i][j + 1] >= mod) {
                ways[i][j + 1] -= mod;
            }
            mi[i][j + 1] = min(mi[i][j + 1], mi[i][j]);
            if (s[j] != '0' && j + (j - i) <= n) {
                int delta = j - i;
                int len = min(j - i, lcp[i][j]);
                if (len != j - i && s[i + len] > s[j + len]) {
                    ++delta;
                }
                if (delta > 0 && j + delta <= n) {
                    ways[j][j + delta] += ways[i][j];
                    if (ways[j][j + delta] >= mod) {
                        ways[j][j + delta] -= mod;
                    }
                    mi[j][j + delta] = min(mi[j][j + delta], mi[i][j] + 1);
                }
            }
        }
    }


    long long ans1 = 0;
    string ans2 = string(n + n, '1');

    for (int i = 0; i < n; ++i) {
        ans1 += ways[i][n];
        if (mi[i][n] != 0x3f3f3f3f) {
            //cerr << i << " " << mi[i][n] << endl;
            string v = add(s.substr(i), convert(mi[i][n] + 1));
            ans2 = MIN(ans2, v);

        }
    }
    ans1 %= mod;
    cout << ans1 << endl;
    long long x = 0;
    for (char c : ans2) {
        x = (x * 2 + c - '0') % mod;
    }
    cout << x << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
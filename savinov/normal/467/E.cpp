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
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    in(n);

    int a[n];
    int b[n];

    vector <int> p[n + n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
        b[i] = a[i];
    }

    sort(b, b + n);

    int sz = unique(b, b + n) - b;

    vector <int> v[sz];

    for (int i = 0; i < n; ++i) {
        int po = lower_bound(b, b + sz, a[i]) - b;
        vector <int> & q = v[po];

        int l = max(0, (int)q.size() - 2);
        int r = q.size();

        for (int j = l; j < r; ++j) {
            p[i + n].push_back(q[j]);
        }
        q.push_back(i);
    }

    for (int i = n - 1; i > 0; --i) {
        merge(all(p[i + i]), all(p[i + i + 1]), back_inserter(p[i]));
    }
    int dp[n + 1];
    int z[n + 1];
    PII pp[n + 1];

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        z[i + 1] = i;
        pp[i + 1] = mp(INT_MAX, INT_MAX);
        int po = lower_bound(b, b + sz, a[i]) - b;
        vector <int> & q = v[po];
//        cout << i << endl;
//        for (int t = 0; t < q.size(); ++t) {
//            cout << q[t] << " ";
//        }
//        cout << endl;
        int pos = lower_bound(all(q), i) - q.begin();

        int l = max(0, pos - 2);

        for (int j = l; j < pos; ++j) {

            int L = q[j] + 1, R = q[pos] - 1;

            int X = q[j];

            int po = -1;

            for (L += n, R += n; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
                if (L & 1) {
                    int d = lower_bound(all(p[L]), X) - p[L].begin() - 1;
                    if (d >= 0 && p[L][d] > po) {
                        po = p[L][d];
                    }
                }
                if (!(R & 1)) {
                    int d = lower_bound(all(p[R]), X) - p[R].begin() - 1;
                    if (d >= 0 && p[R][d] > po) {
                        po = p[R][d];
                    }
                }
            }

            if (po >= 0) {
                if (dp[po] + 1 > dp[i + 1]) {
                    dp[i + 1] = dp[po] + 1;
                    z[i + 1] = po;
                    pp[i + 1] = mp(a[po], a[i]);
                }
            }
        }
        if (pos >= 3) {
            if (dp[q[pos - 3]] + 1 > dp[i + 1]) {
                dp[i + 1] = dp[q[pos - 3]] + 1;
                z[i + 1] = q[pos - 3];
                pp[i + 1] = mp(a[i], a[i]);
            }
        }
    }

    vector <int> ans;

    int cur = n;
    //cerr << "OK" << endl;
    while (cur) {
        if (pp[cur] == mp(INT_MAX, INT_MAX)) {
            cur = z[cur];
            continue;
        } else {
            ans.push_back(pp[cur].y);
            ans.push_back(pp[cur].x);
            ans.push_back(pp[cur].y);
            ans.push_back(pp[cur].x);
            cur = z[cur];
        }
    }

    reverse(all(ans));

    cout << ans.size() << endl;

    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }

    if (ans.size()) cout << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}
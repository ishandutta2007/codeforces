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

struct data {
    long long sum;
    int max;
    int maxPos;
};

inline data merge(const data & l, const data & r) {
    data res;
    res.sum = l.sum + r.sum;
    if (l.max > r.max) {
        res.max = l.max;
        res.maxPos = l.maxPos;
    } else {
        res.max = r.max;
        res.maxPos = r.maxPos;
    }
    return res;
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
    in(n); in(m);
    data st[n + n];
    for (int i = 0; i < n; ++i) {
        st[i + n].max = st[i + n].sum = nxt();
        st[i + n].maxPos = i;
    }
    for (int i = n - 1; i > 0; --i) {
        st[i] = merge(st[i + i], st[i + i + 1]);
    }
    while (m--) {
        in(t);
        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt() - 1;
            data res = data {0, INT_MIN, -1};
            for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
                if (l & 1) {
                    res = merge(res, st[l]);
                }
                if (!(r & 1)) {
                    res = merge(res, st[r]);
                }
            }
            cout << res.sum << "\n";
        }
        if (t == 2) {
            int L = nxt() - 1;
            int R = nxt() - 1;
            int x = nxt();
            while (true) {
                /*for (int i = 1; i < n + n; ++i) {
                    cerr << st[i].max << " ";
                }
                cerr << endl;*/
                data res = data {0, INT_MIN, -1};
                for (int l = L + n, r = R + n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
                    if (l & 1) {
                        res = merge(res, st[l]);
                    }
                    if (!(r & 1)) {
                        res = merge(res, st[r]);
                    }
                }
                if (res.max >= x) {
                    //cerr << res.max << " " << res.maxPos << endl;
                    int pos = res.maxPos + n;
                    st[pos].max %= x;
                    st[pos].sum = st[pos].max;
                    for (pos >>= 1; pos; pos >>= 1) {
                        st[pos] = merge(st[pos + pos], st[pos + pos + 1]);
                    }
                } else {
                    break;
                }
            }
        }
        if (t == 3) {
            int pos = nxt() - 1 + n;
            int x = nxt();
            st[pos].max = st[pos].sum = x;
            for (pos >>= 1; pos; pos >>= 1) {
                st[pos] = merge(st[pos + pos], st[pos + pos + 1]);
            }
        }
    }
    return 0;
}
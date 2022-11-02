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

struct F {
    vector <int> t;

    F(int size) {
        t.resize(size);
    }

    int get(int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res += t[r];
        }
        return res;
    }

    void add(int r, int val) {
        for (; r < t.size(); r |= r + 1) {
            t[r] += val;
        }
    }
};

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
    in(n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] = nxt();
    }
    sort(b, b + n);
    int sz = unique(b, b + n) - b;

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b, b + sz, a[i]) - b;
    }
    int count[sz];
    int cnt[sz];
    clr(cnt);
    clr(count);

    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }

    F sum(n + 1);
    F ccc(n + 1);

    for (int i = 0; i < sz; ++i) {
        sum.add(count[i], count[i]);
        ccc.add(count[i], 1);
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        sum.add(count[a[i]], -count[a[i]]);
        ccc.add(count[a[i]], -1);
        --count[a[i]];
        sum.add(count[a[i]], count[a[i]]);
        ccc.add(count[a[i]], 1);
        ans += sum.get(cnt[a[i]]) + cnt[a[i]] * (sz - ccc.get(cnt[a[i]]));
        cnt[a[i]]++;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}
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

struct Event {
    int type;
    int l, r;
    int k;
    int id;

    bool operator<(const Event & V) const {
        if (l != V.l) {
            return l < V.l;
        }
        if (type != V.type) {
            return type < V.type;
        }
        if (r != V.r) {
            return r < V.r;
        }
        return id < V.id;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "afftar";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif

    in(n);

    PII a[n];

    vector <Event> q;

    for (int i = 0; i < n; ++i) {
        a[i].x = nxt();
        a[i].y = nxt();
        q.push_back(Event{1, a[i].x, a[i].y, 0, i});
    }

    in(m);

    int R[m + 1];
    int K[m + 1];

    for (int i = 0; i < m; ++i) {
        in(l); in(r); in(k);
        q.push_back(Event{0, l, r, k, i});
        q.push_back(Event{2, r, -1, k, i});
        R[i] = r;
        K[i] = k;
    }

    sort(all(q));

    auto cmp = [&](int a, int b) {
        return R[a] < R[b] || (R[a] == R[b] && K[a] > K[b]) || (R[a] == R[b] && K[a] == K[b] && a < b);
    };

    int ans[n];

    set <int, decltype(cmp)> ex(cmp);

    for (int i = 0; i < (int)q.size(); ++i) {
        if (q[i].type == 0) {
            ex.insert(q[i].id);
            continue;
        }
        if (q[i].type == 1) {
            R[m] = q[i].r;
            K[m] = 2e9;
            auto it = ex.lower_bound(m);
            if (it == ex.end()) {
                puts("NO");
                return 0;
            }
            int pos = *it;
            ex.erase(pos);
            K[pos]--;
            ans[q[i].id] = pos;
            if (K[pos] > 0) {
                ex.insert(pos);
            }
            continue;
        }
        ex.erase(q[i].id);
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL




    return 0;
}
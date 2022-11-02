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

PII C[1000000];
vector <int> g[1000000];
vector <int> gr[1000000];

map <string, int> ind;

int sz = 0;

int add(string & d) {
    int rr = 0;
    for (int i = 0; i < (int)d.length(); ++i) {
        d[i] = tolower(d[i]);
        if (d[i] == 'r') {
            ++rr;
        }
    }
    auto it = ind.find(d);
    int p;
    if (it == ind.end()) {
        C[sz] = mp(rr, d.length());
        p = sz;
        ind[d] = sz++;
    } else {
        p = it->second;
    }
    return p;
}

char used[1000000];

PII res[1000000];

vector<int> order, comp;

set <int> tt[1000000];

PII cc[1000000];

int co[1000000];

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

int col = 0;

void dfs2 (int v) {
    used[v] = true;
    co[v] = col;
    comp.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}


PII solve(int a) {
    if (res[a] != mp(INT_MAX, INT_MAX)) {
        return res[a];
    }
    res[a] = cc[a];
    for (int to : tt[a]) {
        res[a] = min(res[a], solve(to));
    }
    return res[a];

}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    in(n);

    vector <int> s;

    for (int i = 0; i < n; ++i) {
        string d;
        cin >> d;
        s.push_back(add(d));
        //cout << C[s.back()].x << " " << C[s.back()].y << endl;
    }

    cout << endl;

    in(m);

    while (m--) {
        string A, B;
        cin >> A >> B;
        int f = add(A);
        int t = add(B);

        g[f].push_back(t);
        gr[t].push_back(f);
    }

    clr(used);

    for (int i = 0; i < sz; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    assert(order.size() == sz);
    clr(used);
    //cout << "ADS" << endl;
    for (int i = 0; i < sz; ++i) {
        int v = order[sz - 1 - i];

        if (!used[v]) {
            dfs2(v);
            PII z = mp(INT_MAX, INT_MAX);
            for (int j = 0; j < (int)comp.size(); ++j) {
                //cout << comp[j] << " ";
                z = min(z, C[comp[j]]);
            }
            //cout << endl;
            //cout << endl;
            //cout << z.x << " " << z.y << endl;
            comp.clear();
            cc[col++] = z;
        }
    }
    //cout << "DAS" << endl;
    for (int i = 0;  i < col; ++i) {
        res[i] = mp(INT_MAX, INT_MAX);
    }
    for (int i = 0; i < sz; ++i) {
        for (int to : g[i]) {
            if (co[i] != co[to]) {
                tt[co[i]].insert(co[to]);
            }
        }
    }

    long long A = 0, B = 0;

    for (int x : s) {
        int z = co[x];
        PII d = solve(z);
        A += d.x;
        B += d.y;
    }

    cout << A << " " << B << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}
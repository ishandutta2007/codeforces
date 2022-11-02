#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
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
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 5e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; typedef complex<ld> cbase; inline void fft (vector<cbase> &a, bool invert) {int n = (int)a.size(); for (int i = 1, j = 0; i < n; ++i) {int bit = n >> 1; for (; j >= bit; bit >>= 1) j -= bit; j += bit; if (i < j) swap(a[i], a[j]);} for (int len = 2; len <= n; len <<= 1) {ld ang = 2 * PI / len * (invert ? -1 : 1); cbase wlen(cos(ang), sin(ang)); for (int i = 0; i < n; i += len) {cbase w(1); for (int j=0; j < len / 2; ++j) {cbase u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen;}}} if (invert) for (int i = 0; i < n; ++i) a[i] /= n;} inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(ll a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} struct lnum {vector <int> a; int base; lnum(int num = 0, int base = 1000000000):base(base) {if (!num) a.resize(1); while(num) {a.pb(num % base); num /= base;}} inline int len() const {return a.size();} lnum & operator=(const lnum &l) {if (this != &l) {a = l.a; base = l.base;} return *this;} inline friend lnum operator+(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int ln = l.len(), rn = r.len(); int n = max(ln, rn); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = o; if (i < ln) s += l.a[i]; if (i < rn) s += r.a[i]; o = s >= base; if (o) s -= base; ret.a[i] = s;} if (o) ret.a.push_back(1); return ret;} inline friend lnum operator-(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int n = l.len(); int rn = r.len(); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = l.a[i] - o; if (i < rn) s -= r.a[i]; o = s < 0; if (o) s += base; ret.a[i] = s;} if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator*(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; if (l.len() * r.len() > 1000000) {vector<cbase> fa (l.a.begin(), l.a.end()), fb (r.a.begin(), r.a.end()); int n = 1; while (n < max (l.len(), r.len())) n <<= 1; n <<= 1; fa.resize (n), fb.resize (n); fft (fa, false), fft (fb, false); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft (fa, true); ret.a.resize(n); for (int i = 0; i < n; ++i) ret.a[i] = int (fa[i].real() + 0.5); int carry = 0; for (int i=0; i < n; ++i) {ret.a[i] += carry; carry = ret.a[i] / base; ret.a[i] %= base;}} else {ret.a.resize(l.len() + r.len()); for (int i = 0; i < l.len(); ++i) for (int j = 0, carry = 0; j < r.len() || carry; ++j) {long long cur = ret.a[i + j] + (ll)l.a[i] * (j < r.len() ? r.a[j] : 0) + carry; ret.a[i + j] = cur % base; carry = cur / base;}} while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator/(const lnum &l, const int &r) {lnum ret(0, l.base); ret.a.resize(l.len()); int carry = 0; for(int i = l.len() - 1; i >= 0; --i) {long long cur = l.a[i] + (ll)carry * l.base; ret.a[i] = cur / r; carry = cur % r;} while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back(); return ret;}  inline friend bool operator<(const lnum &l, const lnum &r) {if (l.len() < r.len()) return true; if (l.len() > r.len()) return false; int n = l.len(); for(int i = n - 1; i >= 0; --i) {if (l.a[i] < r.a[i]) return true; if (l.a[i] > r.a[i]) return false;} return false;} inline friend bool operator>(const lnum &l, const lnum &r) {return r < l;} inline friend bool operator==(const lnum &l, const lnum &r) {if (l.len() != r.len()) return false; int n = l.len(); for(int i = n - 1; i; --i) {if (l.a[i] != r.a[i]) return false;} return true;} inline friend bool operator!=(const lnum &l, const lnum &r) {return !(l == r);} inline void print() {if (base == 1000000000) {printf("%d", a.back()); for(int i = a.size() - 2; i >=0; --i) printf("%09d", a[i]);} else {for(int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);}}};

struct edge {
    int from, to, u, cost, f;
    edge(int from, int to, int u, int cost):from(from),to(to),u(u),cost(cost), f(0){}
};

int main()
{
    in(n); in(m);
    vector <edge> e;
    VVI g;
    int str[n];
    int type[n];
    forn(i, n)
    {
        string s;
        cin >> s >> str[i];
        if (s == "ATK")
            type[i] = 0;
        else
            type[i] = 1;
    }
    int N = n;
    int str2[m];
    forn(i, m)
    {
        cin >> str2[i];
    }
    int s = 0;
    int t = n + m + 2;
    g.resize(t + 1);
    int u = max(0, m - n);
    forn(i, n)
    {
        g[m + 1 + i].pb(e.size());
        e.pb(edge{m + 1 + i, t, 1, 0});
        g[t].pb(e.size());
        e.pb(edge{t, m + 1 + i, 0, 0});
    }
    int nn = e.size();
    g[m + 1 + n].pb(e.size());
    e.pb(edge{m + 1 + n, t, 0, 0});
    g[t].pb(e.size());
    e.pb(edge{t, m + 1 + n, 0, 0});

    forn(i, m)
    {
        g[0].pb(e.size());
        e.pb(edge{0, i + 1, 1, 0});

        g[i + 1].pb(e.size());
        e.pb(edge{i + 1, 0, 0, 0});
    }
    forn(i, m)
    {
        forn(j, n + 1)
        {
            if (j == n)
            {
                g[i + 1].pb(e.size());
                e.pb(edge{i + 1, m + 1 + j, 1, -str2[i]});
                g[m + 1 + j].pb(e.size());
                e.pb(edge{m + 1 + j, i + 1, 0, str2[i]});
                continue;
            }
            if (type[j])
            {
                if (str2[i] > str[j])
                {
                     g[i + 1].pb(e.size());
                    e.pb(edge{i + 1, m + 1 + j, 1, 0});
                   g[m + 1 + j].pb(e.size());
                    e.pb(edge{m + 1 + j, i + 1, 0, 0});
                }
            }
            else
            {
                if (str2[i] >= str[j])
                {
                    g[i + 1].pb(e.size());
                    e.pb(edge{i + 1, m + 1 + j, 1, -(str2[i] - str[j])});
                    g[m + 1 + j].pb(e.size());
                    e.pb(edge{m + 1 + j, i + 1, 0, (str2[i] - str[j])});
                }
            }
        }
    }
    n = n + m + 3;
    char used[n];
    int d[n], p[n];
    int flow = 0;
    int cost = 0;
    int ans = 0;
    while (1)
    {
        clr(used);
        forn(i, n)
            d[i] = INF;
        d[s] = 0;
        queue <int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            used[v] = 0;
            for (size_t j=0; j<g[v].size(); ++j)
            {
                int to = e[g[v][j]].to,
                    len = e[g[v][j]].cost;// + phi[v] - phi[to];
                if (e[g[v][j]].u > e[g[v][j]].f && d[to] > d[v] + len)
                {
                    d[to] = d[v] + len;
                    p[to] = g[v][j];
                    if (!used[to])
                    {
                        q.push(to);
                        used[to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) break;
        flow += 1;
        int cur = t;
        cur = t;
        while(cur != s)
        {
            int from = e[p[cur]].from;
            e[p[cur]].f += 1;
            e[p[cur] ^ 1].f -= 1;
            cost += e[p[cur]].cost;
            cur = from;
        }
        remin(ans, cost);
    }

    if (flow == N && u)
    {
        forn(i, e.size())
            e[i].f = 0;
        flow = 0;
        cost = 0;
        e[nn].u = u;
        while (flow < m)
        {
            clr(used);
            forn(i, n)
                d[i] = INF;
            d[s] = 0;
            queue <int> q;
            q.push(s);
            used[s] = 1;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                used[v] = 0;
                for (size_t j=0; j<g[v].size(); ++j)
                {
                    int to = e[g[v][j]].to,
                        len = e[g[v][j]].cost;// + phi[v] - phi[to];
                    if (e[g[v][j]].u > e[g[v][j]].f && d[to] > d[v] + len)
                    {
                        d[to] = d[v] + len;
                        p[to] = g[v][j];
                        if (!used[to])
                        {
                            q.push(to);
                            used[to] = 1;
                        }
                    }
                }
            }
            if (d[t] == INF) break;
            flow += 1;
            int cur = t;
            cur = t;
            while(cur != s)
            {
                int from = e[p[cur]].from;
                e[p[cur]].f += 1;
                e[p[cur] ^ 1].f -= 1;
                cost += e[p[cur]].cost;
                cur = from;
            }
        }
        if (flow == m)
        {
            remin(ans, cost);
        }
    }
    cout << -ans << endl;
    return 0;
}
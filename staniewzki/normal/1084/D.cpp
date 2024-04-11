#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, L> a) { cerr << "(" << a.ST << ", " << a.ND << ")"; }
template<class T> void db(V<T> v) { cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

VI val;
V<VPII> g;

LL best = 0;

LL DFS(int v = 0, int p = -1)
{
    VLL paths;
    for(auto x : g[v])
    {
        if(x.ST != p)
        {
            LL q = DFS(x.ST, v) - x.ND;
            paths.EB(q);
        }
    }

    sort(paths.rbegin(), paths.rend());

    LL ret = val[v];
    if(S(paths) > 0) ret += max(0LL, paths[0]);
    if(S(paths) > 1) ret += max(0LL, paths[1]);

    best = max(ret, best);
    DB(paths);

    if(S(paths) > 1) ret -= max(0LL, paths[1]);

    DB(v, ret);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    val.RS(n);
    REP(i, n)
        cin >> val[i];

    g.RS(n);
    REP(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].EB(b, c);
        g[b].EB(a, c);
    }

    DFS();

    cout << best << "\n";
}
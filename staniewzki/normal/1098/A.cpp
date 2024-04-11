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

template<class T> void db(T a) {cerr << a;}
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}";}
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

VVI g;
VI p;
VI s;
LL ans = 0;

void dfs(int v = 0)
{
    if(s[v] == -1)
    {
        s[v] = 1e9 + 1;
        for(int u : g[v])
            s[v] = min(s[v], s[u]);
    }
        
    int pa = (p[v] == -1 ? 0 : s[p[v]]);
    if(s[v] == 1e9 + 1)
        s[v] = pa;

    ans += s[v] - pa;
    if(s[v] - pa < 0)
        ans = -1e18;

    for(int u : g[v])
        dfs(u);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    p.RS(n);
    g.RS(n);
    p[0] = -1;
    FOR(i, 1, n - 1)
    {
        cin >> p[i];
        p[i]--;
        g[p[i]].EB(i);
    }

    s.RS(n);
    REP(i, n)
        cin >> s[i];
    
    dfs();
    
    if(ans < 0) ans = -1;
    cout << ans << "\n";
}
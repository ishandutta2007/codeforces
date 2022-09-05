#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000;
const LL LINF = INF * (LL) INF;


const int MAX = 2100;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int MOD = 998244353;

struct edge {
    int x, y;
    Int c, f;
};
vector<edge> E;
VI g[MAX];
int D[MAX];
int Q[MAX];
int Ptr[MAX];
int N; // number of vertices in the network (required)
void add_edge(int x, int y, Int c)
{
    edge e;
    e.x = x; e.y = y;
    e.c = c; e.f = 0;
    g[x].PB(SZ(E));
    E.PB(e);
    e.x = y; e.y = x;
    e.c = 0; e.f = 0;
    g[y].PB(SZ(E));
    E.PB(e);
}
int bfs (int s, int t)
{
    FOR (i, 0, N)
        D[i] = -1;
    D[s] = 0;
    Q[0] = s;
    int qh = 0, qt = 1;
    while(qh < qt && D[t] == -1)
    {
        int x = Q[qh++];
        FOR (i, 0, SZ(g[x])) {
            int e = g[x][i];
            if (E[e].f == E[e].c) continue;
            int to = E[e].y;
            if (D[to] == -1)
            {
                D[to] = D[x] + 1;
                Q[qt++] = to;
            }
        }
    }
    return D[t];
}
Int dfs (int x, int t, Int flow)
{
    if (x == t || flow == 0) return flow;
    for (; Ptr[x] < SZ(g[x]); Ptr[x]++) {
        int e = g[x][Ptr[x]];
        LL c = E[e].c;
        LL f = E[e].f;
        int to = E[e].y;
        if (c == f) continue;
        if (D[to] == D[x] + 1) {
            LL push = dfs(to, t, min(flow, c - f));
            if (push > 0)
            {
                E[e].f += push;
                E[e^1].f -= push;
                return push;
            }
        }
    }
    return 0;
}
Int Flow (int s, int t)
{
    Int res = 0;
    while(bfs(s, t) != -1)
    {
        FOR (i, 0, N) {
            Ptr[i] = 0;
        }
        while(true)
        {
            Int push = dfs(s, t, (Int)INF * INF);
            if (push == 0) break;
            res += push;
        }
    }
    return res;
}

int main()
{
//        freopen("in.txt", "r", stdin);
    //    ios::sync_with_stdio(false); cin.tie(0);
    
    int n , m;
    
    cin >> n >> m;
    
    N = n + m + 2;
    
    int s = N - 2;
    int t = N - 1;
    
    Int res = 0;
    
    FOR(i,0,n)
    {
        int a;
        cin >> a;
        add_edge(s, i, a);
    }
    
    
    
    FOR(i,0,m)
    {
        int a , b , c;
        cin >> a >> b >> c;
        --a;--b;
        
        add_edge(n + i, t , c);
        add_edge(a , n + i , (Int)INF * INF);
        add_edge(b , n + i , (Int)INF * INF);
        
        res += c;
    }
    
    
    
    
    res -= Flow(s, t);
    
    
    cout << res << endl;
    
    
    
    return 0;
}
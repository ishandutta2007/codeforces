#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _for(i, a, b) for (__typeof__(a) i = (a); i != (b); ++i)
#define foreach(x...) _for(x)
#define forall(i, v) foreach(i, all(v))
#define FU(i, a, b) for(__typeof__(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)
#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-1;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct graph {
    int _ini, _end, delta;
    vi dest, cap, flow, imb;
    vd cost, pot;
    vvi adj;

    int inv(int a) { return a ^ 0x1; }
    
    graph(int n = 0) {
        _ini = _end = -1;
        adj.resize(n);
        imb.resize(n);
    }

    int arc(int i, int j, int u = 0, double c = 0) {
        dest.pb(j);
        adj[i].pb(sz(dest)-1);
        dest.pb(i);
        adj[j].pb(sz(dest)-1);
        cap.pb(u);
        cap.pb(0);
        cost.pb(c);
        cost.pb(-c);
        return sz(dest)-2;
    }

    int orig(int a){ return dest[inv(a)]; }
    int capres(int a){ return cap[a] - flow[a]; }

    vi d, curAdj;

    bool MFbfs(int s, int t) {
        d = vi(sz(adj), INF);
        curAdj = vi(sz(adj));
        d[s] = 0;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            forall(i, adj[u]) {
                int v = dest[*i];
                if (capres(*i) > 0 && d[v] == INF) {
                    d[v] = d[u] + 1; Q.push(v);
                }
            }
        }
        return d[t] != INF;
    }

    int MFdfs(int u, int t, int f) {
        if (u == t) return f;
        for(int &i = curAdj[u]; i < adj[u].size(); ++i) {
            int ar = adj[u][i], v = dest[ar];
            if (d[v] != d[u]+1 || capres(ar) == 0) continue;
            int tmpF = MFdfs(v, t, min(f, capres(ar)));
            if (tmpF) {
                flow[ar] += tmpF;
                flow[inv(ar)] -= tmpF;
                return tmpF;
            }
        }
        return 0;
    }

    int maxflow(int ini, int end) {
        if (_ini != ini || _end != end) {
            flow = vi(sz(dest));
            _ini = ini;
            _end = end;      
        }
        while (MFbfs(ini, end))
            while (MFdfs(ini, end, INF));
        int F = 0;
        forall(a, adj[ini]) F += flow[*a];
        return F;
    }    
};

const int MAXN = 105;

int N, M, U, S;
int a[MAXN], b[MAXN];
vector<int> adj[MAXN];
int f[MAXN][MAXN];

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> a[i];
        U += a[i];
    }
    
    for(int i=0; i<N; i++){
        cin >> b[i];
        S += b[i];
    }
   
    if(U != S){ cout << "NO\n"; return 0; }

    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    graph g(2*N+2);
    
    for(int i=0; i<N; i++){
        g.arc(0, i+1, a[i]); 
        g.arc(i+1, i+N+1, INF);
        g.arc(i+N+1, 2*N+1, b[i]);
        for(int j : adj[i])
            g.arc(i+1, j+N+1, INF);
    }

    int F = g.maxflow(0, 2*N+1);
    if(F != S){ cout << "NO\n"; return 0; }

    cout << "YES\n";    
    
    for(int e=0; e<g.dest.size(); e++){
        if(g.dest[e] < N+1 || g.dest[e] == 2*N+1) continue;
        f[g.dest[g.inv(e)]-1][g.dest[e]-N-1] += g.flow[e];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << f[i][j] << " ";
        cout << "\n";
    }
}
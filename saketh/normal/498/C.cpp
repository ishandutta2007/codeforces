#include <unordered_map>
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

int N, M, v[128], ans;
pair<int, int> edge[128];
unordered_map<int, unordered_map<int, int> > fac;

void factor(int i, int arg){
    if(arg == 1) return;
    for(long long p=2; p*p <= arg; p++){
        if(arg % p) continue;
        while(arg % p == 0){
            fac[p][i]++;
            arg /= p;
        }
        factor(i, arg);
        return;
    }
    fac[arg][i]++;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> v[i];
        factor(i, v[i]);
    }
    for(int i=0; i<M; i++){
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--;
        edge[i].second--;
        if(edge[i].first % 2) swap(edge[i].first, edge[i].second);
    }

    for(auto it : fac){
        int prime = it.first;

        graph g(N+2);
        for(int i=0; i<N; i+=2)
            g.arc(0, i+1, fac[prime][i]);
        for(int i=1; i<N; i+=2)
            g.arc(i+1, N+1, fac[prime][i]);
        for(int i=0; i<M; i++)
            g.arc(edge[i].first+1, edge[i].second+1, INF);

        int add = g.maxflow(0, N+1);
        ans += add;
    } 

    cout << ans << endl;    
    return 0;
}
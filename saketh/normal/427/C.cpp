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

typedef long long ll;

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

    vi depth;
    vi ord, rep;
    int transp(int a) { return (a & 0x1); }

    void dfs_topsort(int u) {
        forall(a, adj[u]) {
            int v = dest[*a];
            if (!transp(*a) && depth[v] == -1) {
                depth[v] = depth[u] + 1;
                dfs_topsort(v);
            }
        }
        ord.pb(u);
    }

    void dfs_compfortcon(int u, int ent) {
        rep[u] = ent;
        forall(a, adj[u]) {
            int v = dest[*a];
            if (transp(*a) && rep[v] == -1) dfs_compfortcon(v, ent);
        }
    }

    void compfortcon() {
        depth = vi(sz(adj), -1);
        ord.clear();
        fu(u, sz(adj)) if (depth[u] == -1) {
            depth[u] = 0;
            dfs_topsort(u);
        }

        rep = vi(sz(adj), -1);
        for (int i = sz(adj)-1; i >= 0; i--) if (rep[ord[i]] == -1)
            dfs_compfortcon(ord[i], ord[i]);
    }
};

const int MAXN = 100005;

int N, M;
int cost[MAXN];
int chp[MAXN];
int way[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> cost[i];
        cost[i]++;
    }

    graph g(N);   
    cin >> M;
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.arc(u, v);
    }

    g.compfortcon();

    for(int i=0; i<N; i++){
        int comp = g.rep[i];
        if(chp[comp] == 0 || chp[comp] > cost[i]){
            chp[comp] = cost[i];
            way[comp] = 1;
        }
        else if(chp[comp] == cost[i]) way[comp]++;
    }

    ll tot = 0;
    ll ways = 1;

    for(int i=0; i<MAXN; i++){
        if(!chp[i]) continue;
        tot += chp[i] - 1;
        ways = ways * way[i] % 1000000007;
    }

    cout << tot << " " << ways << endl;
}
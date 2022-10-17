#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXL = 20;

int N, Q, u, v;
vector<int> adj[MAXN];
int depth[MAXN];
int subtr[MAXN];
int par[MAXN][MAXL];

void dfs(int loc, int prev, int ht){
    depth[loc] = ht;
    par[loc][0] = prev;
    subtr[loc] = 1;
    
    for(int ch : adj[loc])
        if(ch != prev){
            dfs(ch, loc, ht+1);
            subtr[loc] += subtr[ch];
        }
}

int go_up(int a, int k){
    for(int i=0; i<MAXL; i++){
        if(k&1) a = par[a][i];
        k/=2;
    }
    return a;
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    b = go_up(b, depth[b] - depth[a]); 
    for(int i=MAXL-1; i>=0; i--)
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    return (a == b) ? a : par[a][0];
}

int calc(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    int c = lca(a, b);
    int dist = depth[a] + depth[b] - 2 * depth[c];
    if(dist&1) return 0;

    if(depth[a] == depth[b]){
        int ar = go_up(a, dist/2-1);
        int br = go_up(b, dist/2-1);
        return N - subtr[ar] - subtr[br];   
    }

    int br = go_up(b, dist/2-1);
    int mp = par[br][0];
    return subtr[mp] - subtr[br];
}

int main(){
    cin >> N;
    for(int i=0; i<N-1; i++){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0, 0, 0);

    for(int p=1; p<MAXL; p++)
        for(int i=0; i<N; i++)
            par[i][p] = par[par[i][p-1]][p-1];

    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> u >> v;
        if(u == v) cout << N << "\n";
        else cout << calc(u-1, v-1) << "\n";
    }
}
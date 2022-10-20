#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 998244353;

vector<vector<ll>> anc(2000+1);
//dfs
//s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
//L
int L;
void dfs(Graph &G, int s,int i){
    anc[s].push_back(i);
    t++;
    for(int nx:G[s]){
        if(t>=L) break;
        if(vis[nx]==i) continue;
        depth[nx] = depth[s] + 1;
        vis[nx] = i;
        dfs(G,nx,i);
    }
    t--;
}
    

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin >> N;
    Graph G(N+1);
    ll f[N+1]; int r;
    rep(i,N){
        ll p,c; cin >> p >> c;
        G[p].push_back(i+1);
        f[i+1] = c;
    }
    
    //main
    rep(i,N){
        vis.assign(N+1,-1);
        depth.assign(N+1,-1);
        int s = i+1;
        vis[s] = s; depth[s] = 0; t = -1; //s:
        L= 2000000000; //
        dfs(G,s,s); //s: i:dfs
    }
    vis.assign(N+1,-1);
    depth.assign(N+1,-1);
    vis[0] = 0; depth[0] = 0; t = -1; //s:
    L= 2000000000; //
    dfs(G,0,0); //s: i:dfs

    priority_queue<Pr, vector<Pr>, greater<Pr>> go;
    rep(i,N){
        if(f[i+1]==0){
            go.push(make_pair(depth[i+1],i+1));
        }
    }
    ll ans[N+1];
    rep(i,N+1) ans[i] = -1;
    ans[0] = 0;
    int num = 1;
    while(!go.empty()){
        Pr p = go.top(); go.pop();
        ll x = p.first; ll y = p.second;
        ans[y] = num;
        for(ll z:anc[y]){
            f[z]--;
            if(f[z]==0){
                go.push(make_pair(depth[z],z));
            }
        }
        num++;
    }

    string jud = "YES";
    rep(i,N+1){
        if(ans[i]<0) jud = "NO";
    }
    cout << jud << endl;
    if(jud=="NO") return 0;
    rep(i,N){
        cout << ans[i+1] << " ";
    }
    cout << endl;
    //cout << ans << endl;
}
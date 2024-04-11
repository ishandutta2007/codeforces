#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<Pr>>;

const ll mod = 1000000007;

//dfs
//s: i:dfs t:
vector<int> vis;
vector<int> depth;
vector<int> par;
vector<ll> dist;
vector<ll> lv;
//L

ll sum = 0;

void dfs(Graph &G, int s,int i){
    bool leaf = true;
    for(auto p:G[s]){
        auto[nx,w] = p;
        if(vis[nx]==i) continue;
        leaf = false;
        depth[nx] = depth[s] + 1;
        dist[nx] = dist[s] + w;
        par[nx] = s;
        vis[nx] = i;
        dfs(G,nx,i);
    }
    if(leaf){
        lv[s] = 1; sum += dist[s];
    }
    if(par[s]!=-1){
        lv[par[s]] += lv[s];
    }
}
    

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        ll N,S; cin >> N >> S;
        sum = 0;
        Graph G(N+1);
        vector<Tp> ed;
        rep(i,N-1){
            ll a,b,w; cin >> a >> b >> w;
            G[a].push_back(make_pair(b,w));
            G[b].push_back(make_pair(a,w));
            ed.push_back(make_tuple(a,b,w));
        }
        //main
        vis.assign(N+1,-1);
        depth.assign(N+1,-1);
        par.assign(N+1,-1);
        dist.assign(N+1,0);
        lv.assign(N+1,0);
        int s = 1;
        vis[s] = 0; depth[s] = 0;
        dfs(G,s,0); //s: i:dfs
        
        priority_queue<Tp> red;
        rep(i,N-1){
            auto[a,b,w] = ed[i];
            ll c = min(lv[a],lv[b]);
            ll r = (w+1)/2;
            red.push(make_tuple((c*r),w/2,c));
        }
        ll ans = 0;
        while(sum>S){
            auto p = red.top(); red.pop();
            auto[ef,w,c] = p;
            sum -= ef;
            ll r = (w+1)/2;
            red.push(make_tuple((c*r),w/2,c));
            ans++;
        }
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}
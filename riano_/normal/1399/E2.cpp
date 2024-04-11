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
        vector<vector<Tp>> ed(3);
        rep(i,N-1){
            ll a,b,w,cc; cin >> a >> b >> w >> cc;
            G[a].push_back(make_pair(b,w));
            G[b].push_back(make_pair(a,w));
            ed[cc].push_back(make_tuple(a,b,w));
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
        
        vector<priority_queue<Tp>> red(3);
        rep(cc,3){
            rep(i,ed[cc].size()){
                auto[a,b,w] = ed[cc][i];
                ll c = min(lv[a],lv[b]);
                ll r = (w+1)/2;
                red[cc].push(make_tuple((c*r),w/2,c));
            }
        }
        ll osum = sum; ll tg = sum-S;
        vector<ll> one; one.push_back(0);
        ll rr = 0;
        while(rr<tg){
            if(red[1].empty()) break;
            auto p = red[1].top(); red[1].pop();
            auto[ef,w,c] = p;
            rr += ef;
            if(ef==0) break;
            ll r = (w+1)/2;
            red[1].push(make_tuple((c*r),w/2,c));
            one.push_back(rr);
        }
        vector<ll> two; two.push_back(0);
        rr = 0;
        while(rr<tg){
            if(red[2].empty()) break;
            auto p = red[2].top(); red[2].pop();
            auto[ef,w,c] = p;
            rr += ef;
            if(ef==0) break;
            ll r = (w+1)/2;
            red[2].push(make_tuple((c*r),w/2,c));
            two.push_back(rr);
        }
        ll ans = 2e9;
        ll K = one.size();
        ll j = 0;
        ll mm = two[two.size()-1];
        for(ll i=K-1;i>=0;i--){
            ll rn = one[i];
            ll rm = tg-rn;
            if(rm>mm) break;
            while(rm>two[j]){
                j++;
            }
            ans = min(ans,i+j*2);
        }
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}
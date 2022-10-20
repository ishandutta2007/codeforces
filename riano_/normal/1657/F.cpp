#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
 
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
 
//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}
 
    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};
 
//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  
 
const ll mod = 998244353;

void out(vector<ll> &v){
    for(ll x:v) cout << x << " ";
    cout << "\n"; return;
}
 
 
//LCA
vector<vector<Pr>> anc;
vector<int> depth_lca;
ll logN = 0;
void lcapre(graph &g, int s){
    rep(i,logN-1){
        if(anc[s][i].first==-1) break;
        anc[s][i+1] = 
        make_pair(anc[anc[s][i].first][i].first,
        anc[s][i].second+anc[anc[s][i].first][i].second);
    }
 
    for(auto p:g.G[s]){
        int nx = get<0>(p); ll l = get<1>(p); //GraphTp
        if(depth_lca[nx]>=0) continue;
        anc[nx].assign(logN,make_pair(-1,-1));
        anc[nx][0] = make_pair(s,l);
        depth_lca[nx] = depth_lca[s]+1;
        lcapre(g,nx);
    }
}
long long lcadist(int a,int b){
    ll dist = 0;
    if(depth_lca[a]>depth_lca[b]) swap(a,b);
    ll c = b;
    if(depth_lca[a]!=depth_lca[b]){ //b:deeper
        ll d = depth_lca[b];
        for(int i=logN-1;i>=0;i--){
            if(depth_lca[a]+(1LL<<i)<=d){
                d -= (1LL<<i);
                dist += anc[c][i].second;
                c = anc[c][i].first;
            }
        }
    }
    //c&a:same depth now
    ll aa = a,bb = c;
    for(int i=logN-1;i>=0;i--){
        if(anc[aa][i].first!=anc[bb][i].first){
            dist += anc[aa][i].second;
            dist += anc[bb][i].second;
            aa = anc[aa][i].first;
            bb = anc[bb][i].first;
        }
    }
    if(aa!=bb){
        dist += anc[aa][0].second + anc[bb][0].second;
    }
    return dist;
}
long long lca(int a,int b){
    if(depth_lca[a]>depth_lca[b]) swap(a,b);
    ll c = b;
    if(depth_lca[a]!=depth_lca[b]){ //b:deeper
        ll d = depth_lca[b];
        for(int i=logN-1;i>=0;i--){
            if(depth_lca[a]+(1LL<<i)<=d){
                d -= (1LL<<i);
                c = anc[c][i].first;
            }
        }
    }
    //c&a:same depth now
    ll aa = a,bb = c;
    for(int i=logN-1;i>=0;i--){
        if(anc[aa][i].first!=anc[bb][i].first){
            aa = anc[aa][i].first;
            bb = anc[bb][i].first;
        }
    }
    if(aa!=bb){
        aa = anc[aa][0].first;
    }
    return aa;
}
vector<ll> path(ll a,ll b,ll p,graph &G){
    vector<ll> res1,res2;
    ll s = a;
    while(1){
        res1.push_back(s);
        if(s==p) break;
        s = anc[s][0].first;
    }
    res1.pop_back();
    s = b;
    while(1){
        res2.push_back(s);
        if(s==p) break;
        s = anc[s][0].first;
    }
    reverse(all(res2));
    for(ll x:res2){
        res1.push_back(x);
    }
    return res1;
}
    
 
//BFS
vector<ll> bfs(graph &g,int s){
    ll N = g.G.size();
    queue<int> go;
    ll x,y,a,t,l; ll inf = 2e18;
    vector<ll> dist(N,inf);
    go.push(s); dist[s] = 0;
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(auto q:g.G[s]){
            ll x = get<0>(q); ll label = get<2>(q);
            if(dist[x]<=dist[s]+1) continue;
            dist[x] = dist[s] + 1;
            g.par_v[x] = s;
            g.par_e[x] = label;
            go.push(x);
        }
    }
    return dist;
}
 
 
//SCC SCC
void dfs_scc(graph &g,vector<long long> &perm_back,vector<bool> &vis,long long i,int j){
    vis[i] = true;
    for(auto q:g.G[i]){
        ll x = get<0>(q);
        if(vis[x]) continue;
        dfs_scc(g,perm_back,vis,x,j);
    }
    if(j==-1) perm_back.push_back(i);
    else perm_back[i] = j;
}
vector<long long> scc(graph &g){
    int N = g.G.size();
    vector<long long> perm_back;
    vector<bool> vis(N,false);
    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        dfs_scc(g,perm_back,vis,i,-1);
    }
    reverse(perm_back.begin(),perm_back.end());
    graph rev(N);
    for(int i=0;i<N;i++){
        for(auto q:g.G[i]){
            ll x = get<0>(q); ll cost = get<1>(q);
            rev.unite(x,i,cost,true);
        }
    }
    int k = 0;
    vector<long long> scc_label(N);
    vis.assign(N,false);
    for(int i=0;i<N;i++){
        int s = perm_back[i];
        if(vis[s]) continue;
        dfs_scc(rev,scc_label,vis,s,k);
        k++;
    }
    return scc_label;
}
    
 
int main(){
    riano_; ll ans = 0;
    ll N,M,K,H,W,Q,L,R,T,C,A,B,S;
    cin >> N >> Q;
    graph Tr(N+1);
    graph G(2*(N+Q+2));
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        Tr.unite(a,b);
    }
 
    //LCA_prepare
    //main
    if(logN==0){
        ll kk=1;
        while(kk<=Tr.G.size()){ kk*=2; logN++; }
        logN++;
    }
    anc.assign(N+1,{}); depth_lca.assign(N+1,-1);
    int s = 1;
    anc[s].assign(logN,make_pair(-1,-1)); depth_lca[s] = 0; //s: 
    lcapre(Tr,s); //s: 
    //
    //ll tmp = lcadist(G,a,b); //
 
    vector<vector<vector<Pr>>> rest(N+1,vector<vector<Pr>>(26,vector<Pr>{}));
    vector<ll> req(N+1,0);
    rep(i,Q){
        ll x,y; string S; cin >> x >> y >> S;
        auto v = path(x,y,lca(x,y),Tr);
        //out(v);
        M = S.size();
        rep(j,M){
            if(S[j]==S[M-1-j]){
                rest[v[j]][(S[j]-'a')].emplace_back(i+1,2);
            }
            else{
                rest[v[j]][(S[j]-'a')].emplace_back(i+1,0);
                rest[v[j]][(S[M-1-j]-'a')].emplace_back(i+1,1);
            }
            req[v[j]]++;
        }
    }
 
    vector<char> cor(2*N+2,'a');
 
    for(int i=1;i<=N;i++){
        vector<char> cc;
        int cnt = 0;
        if(req[i]==0) continue;
        rep(j,26){
            if(rest[i][j].size()==req[i]){
                cor[2*i+cnt] = (char)('a'+j); cnt++;
                cc.emplace_back((char)('a'+j));
            }
        }
        // cout << i << endl;
        // cout << cc.size() << endl;
        if(cc.size()==0){
            cout << "NO" << endl; return 0;
        }
        else if(cc.size()==1){
            G.unite(2*i+1,2*i,1,true);
            for(char c:cc){
                int a = c-'a';
                for(auto[path_id,path_dir]:rest[i][a]){
                    if(path_dir==2){
                        G.unite(2*N+2*path_id,2*i,1,true);
                        G.unite(2*i+1,2*N+2*path_id+1,1,true);
                        G.unite(2*N+2*path_id+1,2*i,1,true);
                        G.unite(2*i+1,2*N+2*path_id,1,true);
                    } 
                    else{
                        G.unite(2*N+2*path_id+path_dir,2*i,1,true);
                        G.unite(2*i+1,2*N+2*path_id+(1-path_dir),1,true);
                        G.unite(2*N+2*path_id+(1-path_dir),2*i+1,1,true);
                        G.unite(2*i,2*N+2*path_id+path_dir,1,true);
                    }
                }
            }
        }
        else{
            int dir = 0;
            for(char c:cc){
                int a = c-'a';
                for(auto[path_id,path_dir]:rest[i][a]){
                    G.unite(2*N+2*path_id+path_dir,2*i+dir,1,true);
                    G.unite(2*i+(1-dir),2*N+2*path_id+(1-path_dir),1,true);
                    // G.unite(2*N+2*path_id+path_dir,2*i,1,true);
                    // G.unite(2*i+1,2*N+2*path_id+(1-path_dir),1,true);
                    // G.unite(2*N+2*path_id+(1-path_dir),2*i+1,1,true);
                    // G.unite(2*i,2*N+2*path_id+path_dir,1,true);
                }
                dir++;
                //break;
            }
        }
    }

    vector<char> fix(N+1,'a');
 
    //main
    auto v = scc(G);
    for(int i=1;i<=N;i++){
        if(v[2*i]==v[2*i+1]){
            cout << "NO" << endl; return 0;
        }
        if(v[2*i]<v[2*i+1]){
            fix[i] = cor[2*i+1];
        }
        else{
            fix[i] = cor[2*i];
        }
    }

    rep(i,Q){
        if(v[2*N+2*(i+1)]==v[2*N+2*(i+1)+1]){
            cout << "NO" << endl; return 0;
        }
    }
 
    cout << "YES" << endl;
    rep(i,N){
        cout << fix[i+1];
    }
    cout << endl;
    //cout << ans << endl;
}
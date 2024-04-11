#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;
int N,M,K;
int visited[MAX],depth[MAX],par[MAX],color[MAX];
bool used[MAX];
vector<pair<int,int>> G[MAX],tree[MAX];
pair<int,int> edge[MAX];

void maketree(int u,int dep){
    visited[u]=1;
    depth[u]=dep;
    for(auto to:G[u]){
        if(visited[to.fi]) continue;
        used[to.se]=1;
        tree[u].push_back(to);
        par[to.fi]=u;
        color[to.fi]=1-color[u];
        maketree(to.fi,dep+1);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>K;
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        edge[i]={a,b};
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
    }
    
    maketree(0,0);
    
    for(int i=0;i<M;i++){
        if(used[i]) continue;
        int a=edge[i].fi,b=edge[i].se;
        if(depth[a]>depth[b]) swap(a,b);
        if(depth[b]-depth[a]+1<=K){
            vector<int> ans;
            while(a!=b){
                ans.push_back(b);
                b=par[b];
            }
            ans.push_back(a);
            
            cout<<2<<endl;
            cout<<si(ans)<<endl;
            for(int a:ans) cout<<a+1<<" ";
            cout<<endl;
            
            return 0;
        }
    }
    
    pair<int,pair<int,int>> mi=mp(INF,mp(-1,-1));
    
    for(int i=0;i<N;i++){
        for(auto to:G[i]){
            if(used[to.se]) continue;
            if(depth[i]<depth[to.fi]) continue;
            
            chmin(mi,mp(depth[i]-depth[to.fi],mp(to.fi,i)));
        }
    }
    
    if(mi.fi==INF){
        cout<<1<<endl;
        vector<int> ans,ans2;
        
        for(int i=0;i<N;i++){
            if(color[i]==0) ans.push_back(i);
            else ans2.push_back(i);
        }
        
        if(si(ans)>=(K+1)/2){
            for(int i=0;i<(K+1)/2;i++) cout<<ans[i]+1<<" ";
            cout<<endl;
        }else{
            for(int i=0;i<(K+1)/2;i++) cout<<ans2[i]+1<<" ";
            cout<<endl;
        }
    }else{
        vector<int> ans,ans2;
        int a=mi.se.fi,b=mi.se.se;
        while(a!=b){
            ans.push_back(b);
            b=par[b];
        }
        ans.push_back(a);
        
        cout<<1<<endl;
        for(int i=0;si(ans2)<(K+1)/2;i+=2) ans2.push_back(ans[i]);
        for(int a:ans2) cout<<a+1<<" ";
        cout<<endl;
    }
    
    
    
    
    
}
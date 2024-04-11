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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;
vector<pair<int,ll>> G[MAX];
ll point[MAX],dp[MAX];
ll ans=0;
int N;

void DFS(int u,int p){
    
    for(auto to:G[u]){
        if(to.fi==p) continue;
        
        DFS(to.fi,u);
        
        chmax(dp[u],dp[to.fi]-to.se);
    }
    
    dp[u]+=point[u];
}

void solve(int u,int p){
    
    chmax(ans,dp[u]);
    
    //cout<<u<<" "<<p<<endl;
    //for(int i=0;i<N;i++) cout<<i<<" "<<dp[i]<<endl;
    
    //cout<<endl;
    
    vector<ll> A(si(G[u]),-INF),l,r;
    
    for(int i=0;i<si(G[u]);i++){
        //if(G[u][i].fi==p) continue;
        A[i]=dp[G[u][i].fi]-G[u][i].se;
    }
    
    l=A;
    r=A;
    
    for(int i=1;i<si(l);i++) chmax(l[i],l[i-1]);
    for(int i=si(r)-2;i>=0;i--) chmax(r[i],r[i+1]);
    
    //for(int i=0;i<si(G[u]);i++) cout<<A[i]<<" ";
    //cout<<endl;
    
    for(int i=0;i<si(G[u]);i++){
        auto to=G[u][i];
        
        if(to.fi==p) continue;
        
        ll a,b;
        a=dp[u];
        b=dp[to.fi];
        
        dp[u]=0;
        if(i) chmax(dp[u],l[i-1]);
        if(i+1<si(r)) chmax(dp[u],r[i+1]);
        
        //cout<<dp[u]<<" "<<u<<endl;
        
        dp[u]+=point[u];
        
        chmax(dp[to.fi],dp[u]+point[to.fi]-to.se);
        
        solve(to.fi,u);
        
        dp[u]=a;
        dp[to.fi]=b;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>point[i];
    
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(mp(b,c));
        G[b].push_back(mp(a,c));
    }
    
    DFS(0,-1);
    
    //for(int i=0;i<N;i++) cout<<dp[i]<<endl;
    solve(0,-1);
    
    for(int i=0;i<N;i++) chmax(ans,point[i]);
    
    cout<<ans<<endl;
}
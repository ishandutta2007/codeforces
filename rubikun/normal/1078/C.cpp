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
const int mod=998244353,MAX=300005,INF=1<<30;
vector<int> G[MAX];
ll dp[MAX][3];

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

void DFS(int u,int p){
    
    dp[u][0]=1;
    dp[u][2]=1;
    
    vector<ll> X,Y;
    ll seki=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        
        dp[u][0]*=(dp[to][0]+dp[to][1]);
        dp[u][0]%=mod;
        
        X.push_back((dp[to][0]+dp[to][2])%mod);
        Y.push_back((dp[to][0]+2*dp[to][1])%mod);
        seki*=Y.back();
        seki%=mod;
        
        dp[u][2]*=(dp[to][0]+2*dp[to][1])%mod;
        dp[u][2]%=mod;
        
    }
    
    for(int i=0;i<si(X);i++){
        dp[u][1]+=seki*rui(Y[i],mod-2)%mod*X[i]%mod;
        dp[u][1]%=mod;
    }
    
    dp[u][2]-=dp[u][0];
    if(dp[u][2]<0) dp[u][2]+=mod;
    
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    DFS(0,-1);
    
    cout<<(dp[0][0]+dp[0][1])%mod<<endl;
    
}
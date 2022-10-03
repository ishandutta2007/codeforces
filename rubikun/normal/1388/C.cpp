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
bool ok=false;
int N,M;
vector<int> G[MAX];
ll dp[MAX][2],p[MAX],h[MAX];

void DFS(int u,int pp){
    
    for(int to:G[u]){
        if(to==pp) continue;
        
        DFS(to,u);
        
        dp[u][0]+=dp[to][0];
        dp[u][1]+=dp[to][1];
    }
    
    dp[u][1]+=p[u];
    
    ll a=(dp[u][0]+dp[u][1]+h[u])/2,b=(dp[u][0]+dp[u][1]-h[u])/2;
    
    if(a+b==dp[u][0]+dp[u][1]&&a-b==h[u]&&a>=dp[u][0]&&b<=dp[u][1]&&a>=0&&b>=0){
        dp[u][0]=a;
        dp[u][1]=b;
    }else ok=false;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        cin>>N>>M;
        for(int i=0;i<N;i++){
            G[i].clear();
            dp[i][0]=dp[i][1]=0;
            p[i]=0;
            h[i]=0;
        }
        ok=true;
        for(int i=0;i<N;i++) cin>>p[i];
        for(int i=0;i<N;i++) cin>>h[i];
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        DFS(0,-1);
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}
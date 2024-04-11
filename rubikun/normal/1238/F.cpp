#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
vector<int> G[MAX];
int dp[MAX];
int ans,root;

void DFS(int u,int p){
    if(G[u].size()==1){
        dp[u]=1;
        return;
    }
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        dp[u]=max(dp[u],dp[to]);
    }
    if(u==root) dp[u]+=G[u].size();
    else dp[u]+=G[u].size()-1;
}

void solve(int u,int p){
    
    vector<pair<int,int>> ma;
    ma.push_back({0,-1});
    ma.push_back({1,-1});
    
    for(int to:G[u]){
        if(to==p) continue;
        ma.push_back({dp[to],to});
    }
    sort(all(ma));
    reverse(all(ma));
    
    ans=max(ans,dp[u]+ma[1].first-1);
    
    //cout<<u<<" "<<dp[u]<<" "<<dp[u]+ma[1].first-1<<endl;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        int a=dp[u],b=dp[to];
        
        if(to!=ma[0].second){
            dp[u]=ma[0].first+G[u].size()-1;
            dp[to]=max(dp[to]+1,int(dp[u]+G[to].size()));
        }else{
            dp[u]=ma[1].first+G[u].size()-1;
            dp[to]=max(dp[to]+1,int(dp[u]+G[to].size()));
        }
        
        solve(to,u);
        
        dp[u]=a;
        dp[to]=b;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            dp[i]=0;
        }
        ans=0;
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(N==2){
            cout<<2<<endl;
            continue;
        }
        for(int i=0;i<N;i++){
            if(G[i].size()>=2){
                root=i;
                DFS(i,-1);
                //for(int i=0;i<N;i++) cout<<i<<" "<<dp[i]<<endl;
                solve(i,-1);
                break;
            }
        }
        
        //for(int i=0;i<N;i++) cout<<i<<" "<<dp[i]<<endl;
        
        cout<<ans<<endl;
        
    }
}
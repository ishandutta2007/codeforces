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
ll v[MAX][2];
vector<int> G[MAX];
ll dp[MAX][2];

void solve(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        solve(to,u);
    }
    
    for(int to:G[u]){
        if(to==p) continue;
        for(int i=0;i<2;i++){
            ll ma=0;
            for(int j=0;j<2;j++){
                chmax(ma,dp[to][j]+abs(v[u][i]-v[to][j]));
            }
            dp[u][i]+=ma;
        }
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
            v[i][0]=v[i][1]=0;
            dp[i][0]=dp[i][1]=0;
        }
        
        for(int i=0;i<N;i++) cin>>v[i][0]>>v[i][1];
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        solve(0,-1);
        
        cout<<max(dp[0][0],dp[0][1])<<"\n";
    }
}
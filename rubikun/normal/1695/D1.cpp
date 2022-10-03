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
const int mod=998244353,MAX=2005,INF=1<<30;

vector<int> G[MAX];
int dp[MAX][2];

void solve(int u,int p){
    vector<int> A;
    int sum=0;
    for(int to:G[u]){
        if(to==p) continue;
        solve(to,u);
        A.push_back(dp[to][1]-dp[to][0]);
        sum+=dp[to][1];
    }
    sort(all(A));
    if(si(A)==0){
        dp[u][0]=0;
        dp[u][1]=1;
    }else if(si(A)==1){
        dp[u][0]=sum-A.back();
        dp[u][1]=sum;
    }else{
        dp[u][0]=sum-A.back();
        dp[u][1]=sum-A.back();
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
            dp[i][0]=dp[i][1]=INF;
        }
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans=INF;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) dp[j][0]=dp[j][1]=INF;
            solve(i,-1);
            chmin(ans,dp[i][0]+1);
            chmin(ans,dp[i][1]+1);
            //for(int j=0;j<N;j++) cout<<dp[j][0]<<" "<<dp[j][1]<<endl;
            //cout<<endl;
        }
        if(N==1) ans=0;
        cout<<ans<<endl;
    }
}
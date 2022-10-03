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
const int mod=998244353,MAX=1005,INF=1<<29;
int dis[MAX];
int dp[MAX][MAX*13];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=2;i<MAX;i++) dis[i]=INF;
    queue<int> Q;Q.push(1);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=1;i<=u;i++){
            int to=u+u/i;
            if(to>1000) continue;
            if(chmin(dis[to],dis[u]+1)) Q.push(to);
        }
    }
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N,K;cin>>N>>K;
        vector<int> B(N),C(N);
        for(int i=0;i<N;i++){
            int x;cin>>x;
            B[i]=dis[x];
        }
        for(int i=0;i<N;i++){
            cin>>C[i];
        }
        for(int i=0;i<=N;i++) for(int j=0;j<=13*N;j++) dp[i][j]=-INF;
        dp[0][0]=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<=12*i;j++){
                chmax(dp[i+1][j],dp[i][j]);
                chmax(dp[i+1][j+B[i]],dp[i][j]+C[i]);
            }
        }
        int ans=0;
        for(int j=0;j<=min(12*N,K);j++) chmax(ans,dp[N][j]);
        cout<<ans<<"\n";
    }
}
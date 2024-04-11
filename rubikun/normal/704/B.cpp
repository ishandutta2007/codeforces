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
const int mod=1000000007,MAX=5005;
const ll INF=1LL<<60;

ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,s,t;cin>>N>>s>>t;
    s--;t--;
    vector<ll> x(N),a(N),b(N),c(N),d(N);
    for(int i=0;i<N;i++) cin>>x[i];
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) cin>>b[i];
    for(int i=0;i<N;i++) cin>>c[i];
    for(int i=0;i<N;i++) cin>>d[i];
    
    for(int i=0;i<N;i++){
        a[i]+=x[i];
        b[i]-=x[i];
        c[i]+=x[i];
        d[i]-=x[i];
    }
    
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=INF;
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            if(dp[i][j]==INF) continue;
            if(i&&j==0) continue;
            
            if(i==s){
                if(i+1<N) chmin(dp[i+1][j+1],dp[i][j]+d[i]);
                if(i&&j) chmin(dp[i+1][j-1],dp[i][j]+c[i]);
            }else if(i==t){
                if(i+1<N) chmin(dp[i+1][j+1],dp[i][j]+b[i]);
                if(i&&j) chmin(dp[i+1][j-1],dp[i][j]+a[i]);
            }else{
                if(i+2<N) chmin(dp[i+1][j+2],dp[i][j]+d[i]+b[i]);
                if(i+1<N&&i&&!(j==1&&t<i)) chmin(dp[i+1][j],dp[i][j]+d[i]+a[i]);
                if(i+1<N&&i&&!(j==1&&s<i)) chmin(dp[i+1][j],dp[i][j]+c[i]+b[i]);
                if(i>=2&&j>=2) chmin(dp[i+1][j-2],dp[i][j]+c[i]+a[i]);
            }
        }
    }
    
    cout<<dp[N][0]<<endl;
    
}
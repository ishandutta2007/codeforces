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
const int mod=1000000007,MAX=5055;
const ll INF=1LL<<60;
ll dp[MAX][MAX/2][5];

ll f(ll a,ll b){
    return max(0LL,a-b+1);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX/2;j++) for(int k=0;k<5;k++) dp[i][j][k]=INF;
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    if(N==1){
        cout<<0<<endl;
        return 0;
    }
    
    A.push_back(-1000000);
    
    dp[1][0][0]=0;
    dp[1][1][1]=0;
    dp[1][0][2]=0;
    dp[1][0][3]=f(A[0],A[1]);
    dp[1][0][4]=f(A[0],A[1]);
    
    for(int i=1;i<N;i++){
        for(int j=0;j<=(i+1)/2;j++){
            chmin(dp[i+1][j][0],dp[i][j][1]+f(A[i],A[i-1]));
            chmin(dp[i+1][j][4],dp[i][j][1]+max(f(A[i],A[i-1]),f(A[i],A[i+1])));
            
            chmin(dp[i+1][j+1][1],dp[i][j][3]);
            chmin(dp[i+1][j+1][1],dp[i][j][4]);
            
            chmin(dp[i+1][j][2],dp[i][j][0]);
            chmin(dp[i+1][j][2],dp[i][j][2]);
            
            chmin(dp[i+1][j][3],dp[i][j][0]+f(A[i],A[i+1]));
            chmin(dp[i+1][j][3],dp[i][j][2]+f(A[i],A[i+1]));
        }
    }
    
    vector<ll> ans((N+1)/2+1,INF);
    
    for(int j=0;j<=(N+1)/2;j++){
        for(int k=0;k<5;k++){
            chmin(ans[j],dp[N][j][k]);
        }
    }
    
    for(int j=1;j<si(ans);j++) cout<<ans[j]<<" ";
    cout<<endl;
    
}
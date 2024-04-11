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

int dp[103][103][10003];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),B(N);
    int bsum=0;
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
        bsum+=B[i];
    }
    
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=100*i;k++){
                if(dp[i][j][k]<0) continue;
                chmax(dp[i+1][j][k],dp[i][j][k]);
                chmax(dp[i+1][j+1][k+A[i]],dp[i][j][k]+B[i]);
            }
        }
    }
    
    for(int j=1;j<=N;j++){
        double ans=0;
        for(int k=0;k<=100*N;k++){
            if(dp[N][j][k]>=0) chmax(ans,min(double(k),double(dp[N][j][k]+bsum)/2.0));
        }
        cout<<setprecision(25)<<ans<<" ";
    }
    cout<<endl;
}
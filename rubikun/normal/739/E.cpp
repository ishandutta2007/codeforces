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

//#define double long double

pair<double,int> dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,a,b;cin>>N>>a>>b;
    vector<double> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    double left=-1e-5,right=N+1e-5;
    double ans=0;
    
    for(int q=0;q<40;q++){
        double mid=(left+right)/2;
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) dp[i][j]=mp(-INF,0);
        dp[0][0]=mp(0,0);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<=i;j++){
                if(j+1<=a){
                    chmax(dp[i+1][j+1],mp(dp[i][j].fi+A[i],dp[i][j].se));
                    chmax(dp[i+1][j+1],mp(dp[i][j].fi+A[i]+B[i]-A[i]*B[i]-mid,dp[i][j].se+1));
                }
                chmax(dp[i+1][j],mp(dp[i][j].fi+B[i]-mid,dp[i][j].se+1));
                chmax(dp[i+1][j],dp[i][j]);
            }
        }
        
        //cout<<mid<<" "<<dp[N][a].fi<<" "<<dp[N][a].se<<endl;
        
        if(dp[N][a].se>=b){
            left=mid;
            ans=dp[N][a].fi+(mid*b);
        }else{
            right=mid;
        }
    }
    
    cout<<fixed<<setprecision(25)<<ans<<endl;
}
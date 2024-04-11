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
const int mod=1000000007,MAX=5205;
const ll INF=1LL<<60;

long double dp[53][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,T;cin>>N>>T;
    
    vector<long double> A(N),B(N),C(N);
    for(int i=0;i<N;i++) cin>>A[i]>>B[i]>>C[i];
    
    long double left=0.0,right=INF;
    
    for(int q=0;q<100;q++){
        long double mid=(left+right)/2.0;
        
        for(int j=0;j<=T;j++) dp[N][j]=0;
        for(int i=0;i<N;i++) for(int j=0;j<=T;j++) dp[i][j]=INF;
        
        for(int i=N-1;i>=0;i--){
            long double a,b,c;
            a=A[i];b=B[i];c=C[i];
            
            for(int j=0;j<=T;j++){
                chmin(dp[i][j],mid);
                if(j+a>T) continue;
                
                if(j+b>T){
                    chmin(dp[i][j],((dp[i+1][j+int(a)]+a)*c+(mid+b)*(100.0-c))/100.0);
                }else{
                    chmin(dp[i][j],((dp[i+1][j+int(a)]+a)*c+(dp[i+1][j+int(b)]+b)*(100.0-c))/100.0);
                }
            }
        }
        
        if(dp[0][0]==mid) left=mid;
        else right=mid;
    }
    
    cout<<fixed<<setprecision(25)<<right<<endl;
    
}
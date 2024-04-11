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
const int mod=998244353,MAX=105;
const ll INF=1LL<<60;

bool dp[MAX][MAX*MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        for(int i=0;i<=N;i++) for(int j=0;j<=N*100;j++) dp[i][j]=0;
        dp[0][0]=true;
        ll sum=0,sumsum=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<=i*100;j++){
                dp[i+1][j+A[i]]|=dp[i][j];
                dp[i+1][j+B[i]]|=dp[i][j];
            }
            sum+=A[i]+B[i];
            sumsum+=A[i]*A[i];
            sumsum+=B[i]*B[i];
        }
        for(int j=sum/2;j>=0;j--){
            if(dp[N][j]){
                ll X=j,Y=sum-j;
                ll ans=0;
                ans-=2*sumsum;
                ans+=2*X*X;
                ans+=2*Y*Y;
                ans+=2*(N-1)*sumsum;
                ans/=2;
                cout<<ans<<"\n";
                break;
            }
        }
    }
}
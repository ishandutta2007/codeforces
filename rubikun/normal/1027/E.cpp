#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=503,INF=1<<30;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    dp[0][0]=1;
    
    for(int i=1;i<=N;i++){
        for(int from=0;from<i;from++){
            for(int j=0;j<=from;j++){
                dp[i][max(j,i-from)]+=dp[from][j];
                dp[i][max(j,i-from)]%=mod;
            }
        }
    }
    
    ll ans=0;
    
    for(int j=0;j<=N;j++){
        for(int k=0;k<=N;k++){
            if(j*k<K) ans+=dp[N][j]*dp[N][k]%mod;
            ans%=mod;
        }
    }
    
    cout<<(ans*2)%mod<<endl;
}
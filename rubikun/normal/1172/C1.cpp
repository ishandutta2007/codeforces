#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=55,INF=1<<30;
ll dp[MAX][MAX][MAX];

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A(N),B(N);
    int sum=0,suma=0,sumb=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0) A[i]=-1;
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
        if(A[i]==-1) sumb+=B[i];
        else suma+=B[i];
        
        sum+=B[i];
    }
    
    for(int t=0;t<N;t++){
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        if(A[t]==1) suma-=B[t];
        else sumb-=B[t];
        
        for(int i=0;i<M;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;j+k<=i;k++){
                    int l=i-j-k;
                    int wsum=sum+A[t]*j+k-l,wsuma=suma+k,wsumb=sumb-l;
                    if(wsum<=0) continue;
                    if(B[t]+A[t]*j<0) continue;
                    
                    dp[i+1][j+1][k]+=dp[i][j][k]*(B[t]+A[t]*j)%mod*rui(wsum,mod-2)%mod;
                    dp[i+1][j+1][k]%=mod;
                    
                    dp[i+1][j][k+1]+=dp[i][j][k]*wsuma%mod*rui(wsum,mod-2)%mod;
                    dp[i+1][j][k+1]%=mod;
                    
                    dp[i+1][j][k]+=dp[i][j][k]*wsumb%mod*rui(wsum,mod-2)%mod;
                    dp[i+1][j][k]%=mod;
                }
            }
        }
        
        ll ans=0;
        
        for(int j=0;j<=M;j++){
            if(B[t]+A[t]*j>=0){
                for(int k=0;k<=M;k++){
                    ans+=(B[t]+A[t]*j)*dp[M][j][k];
                    ans%=mod;
                }
            }
        }
        
        cout<<ans<<"\n";
        
        if(A[t]==1) suma+=B[t];
        else sumb+=B[t];
    }
}
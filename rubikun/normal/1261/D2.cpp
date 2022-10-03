#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,MAX_LOG=20;
const ll INF=1LL<<60;

ll inv[MAX],fac[MAX],finv[MAX];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

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
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;
    int K;cin>>N>>K;
    make();
    vector<int> A(N);
    int cnt=0;
    ll sum=0;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        if(A[i]==A[(i+1)%N]) cnt++;
    }
    
    N=N-cnt;
    for(int i=1;i<=N;i++){
        if(i%2==0){
            sum+=(comb(N,i)*(((mod+rui(2,i)-comb(i,i/2))%mod)%mod*rui(2,mod-2)%mod)%mod)*rui(K-2,N-i)%mod;
            sum%=mod;
        }else{
            sum+=(comb(N,i)*rui(2,i-1)%mod)*rui(K-2,N-i)%mod;
            sum%=mod;
        }
        //cout<<sum<<endl;
    }
    
    sum*=rui(K,cnt);
    sum%=mod;
    cout<<sum<<endl;
    
    /*for(int i=0;i<N;i++){
        for(int j=1;j<4000;j++){
            if(dp[i][j]==0) continue;
            if(A[i]==A[(i+1)%N]){
                dp[i+1][j]+=dp[i][j]*K;
                dp[i+1][j]%=mod;
            }else{
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j]+=dp[i][j]*(K-2);
                dp[i+1][j-1]+=dp[i][j];
                
                dp[i+1][j+1]%=mod;
                dp[i+1][j]%=mod;
                dp[i+1][j-1]%=mod;
            }
        }
    }
    
    ll ans=0;
    for(int j=2001;j<=4000;j++){
        ans+=dp[N][j];
        ans%=mod;
    }
    
    cout<<ans<<endl;*/
}
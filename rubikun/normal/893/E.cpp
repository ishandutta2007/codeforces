#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

ll dp[21][MAX],parity[2][MAX];
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

int main(){
    
    make();
    
    int Q;cin>>Q;
    for(int j=2;j<=1000000;j++) dp[1][j]=1;
    ll start=2;
    for(ll i=1;i<=20;i++){
        for(ll j=start;j<=500000;j++){
            if(dp[i][j]==0) continue;
            for(ll k=2;j*k<=1000000;k++){
                dp[i+1][j*k]+=dp[i][j];
                dp[i+1][j*k]%=mod;
            }
        }
        start*=2;
    }
    
    parity[0][0]=1;
    for(int j=0;j<1000000;j++){
        parity[0][j+1]+=(parity[0][j]+parity[1][j]);
        parity[1][j+1]+=(parity[0][j]+parity[1][j]);
        
        parity[0][j+1]%=mod;
        parity[1][j+1]%=mod;
    }
    
    while(Q){
        int x,y;
        //cin>>x>>y;
        scanf("%d%d",&x,&y);
        if(x==1){
            cout<<parity[0][y]<<"\n";
            Q--;
        }else{
            ll sum=0;
            for(int i=1;i<=min(20,y);i++){
                ll a=dp[i][x];
                a*=comb(y,i);
                a%=mod;
                sum+=a;
                sum%=mod;
            }
            sum*=(parity[0][y]);
            sum%=mod;
            
            cout<<sum<<"\n";
            Q--;
        }
    }
    
}
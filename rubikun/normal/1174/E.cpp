#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000005,INF=1<<30;

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
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    int N;cin>>N;
    int d;
    for(int i=19;i>=0;i--){
        if(N&(1<<i)){
            d=i;
            break;
        }
    }
    if(N<(1<<(d-1))*3){
        ll ans=fac[N-1];
        ll now=(1<<d),used=1;
        now/=2;
        
        for(now;now>=2;used=N/now,now/=2){
            ans*=ll(N/now-used);
            ans%=mod;
            
            ans*=rui(N-used,mod-2);
            ans%=mod;
            
            //cout<<now<<" "<<used<<endl;
        }
        
        cout<<ans<<endl;
    }else{
        //if(N>=12) return 1;
        ll sum=0;
        for(int j=1;j<d;j++){
            ll ans=fac[N-1];
            ll now=(1<<(d-1))*3,used=1;
            int k=1;
            now/=2;
            
            for(now;now>=2;){
                ans*=ll(N/now-used);
                ans%=mod;
                
                ans*=rui(N-used,mod-2);
                ans%=mod;
                
                if(j==k){
                    used=N/now;
                    now/=3;
                    //used=N/now;
                }else{
                    used=N/now;
                    now/=2;
                    //used=N/now;
                }
                k++;
            }
            //cout<<ans<<endl;
            sum+=ans;
            sum%=mod;
        }
        
        //cout<<sum<<endl;
        
        ll ans=fac[N-2]*2%mod;
        ll now=(1<<(d-1)),used=3;
        now/=2;
        
        for(now;now>=2;used=N/now,now/=2){
            ans*=ll(N/now-used);
            ans%=mod;
            
            ans*=rui(N-used,mod-2);
            ans%=mod;
        }
        
        //cout<<ans<<endl;
        
        sum+=ans;
        sum%=mod;
        
        ans=fac[N-1];
        now=(1<<d);used=1;
        now/=2;
        
        for(now;now>=2;used=N/now,now/=2){
            ans*=ll(N/now-used);
            ans%=mod;
            
            ans*=rui(N-used,mod-2);
            ans%=mod;
            
            //if(now==(1<<d)/2) used++;
            
            //cout<<ans<<" "<<used<<endl;
        }
        sum+=ans;
        sum%=mod;
        
        //cout<<ans<<endl;
        
        cout<<sum<<endl;
    }
}
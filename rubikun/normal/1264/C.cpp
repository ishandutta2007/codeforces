#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18;
const ll INF=1LL<<60;

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
    
    int N,Q;cin>>N>>Q;
    vector<ll> P(N+1),mul(N+1),sum(N+1);
    set<int> SE;
    SE.insert(1);
    SE.insert(N+1);
    
    for(int i=0;i<N;i++){
        cin>>P[i+1];
        P[i+1]*=rui(100,mod-2);
        P[i+1]%=mod;
    }
    
    mul[0]=1;
    for(int i=1;i<=N;i++){
        mul[i]=mul[i-1]*P[i];
        mul[i]%=mod;
    }
    
    sum[0]=0;
    sum[1]=1;
    for(int i=2;i<=N;i++){
        sum[i]=sum[i-1]+mul[i-1];
        if(sum[i]>=mod) sum[i]-=mod;
    }
    
    ll now=sum[N]*rui(mul[N],mod-2)%mod;
    
    while(Q--){
        int a;cin>>a;
        if(SE.find(a)!=SE.end()){
            
            SE.erase(a);
            
            auto right=SE.lower_bound(a);
            auto left=right;
            left--;
            
            int l=*left,r=*right-1;
            
            ll A=(mod+sum[r]-sum[l-1]);
            ll B=mul[r];
            
            now+=A*rui(B,mod-2)%mod;
            
            A=(mod+sum[a-1]-sum[l-1]);
            B=mul[a-1];
            
            now+=mod-A*rui(B,mod-2)%mod;
            
            A=(mod+sum[r]-sum[a-1]);
            B=mul[r];
            
            now+=mod-A*rui(B,mod-2)%mod;
            now%=mod;
            
        }else{
            auto right=SE.lower_bound(a);
            auto left=right;
            left--;
            
            int l=*left,r=*right-1;
            
            ll A=(mod+sum[r]-sum[l-1]);
            ll B=mul[r];
            
            now+=mod-A*rui(B,mod-2)%mod;
            
            A=(mod+sum[a-1]-sum[l-1]);
            B=mul[a-1];
            
            now+=A*rui(B,mod-2)%mod;
            
            A=(mod+sum[r]-sum[a-1]);
            B=mul[r];
            
            now+=A*rui(B,mod-2)%mod;
            now%=mod;
            
            
            SE.insert(a);
        }
        
        cout<<now<<endl;
    }
    
}
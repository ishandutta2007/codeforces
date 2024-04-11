#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200003,INF=1<<30;

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
    
    ll N;cin>>N;
    for(ll i=1;i<=N-1;i++){
        ll sum=0;
        sum+=2*10*9*rui(10,N-i-1)%mod;
        sum%=mod;
        
        sum+=(N-1-i)*10*9*9%mod*rui(10,N-i-2)%mod;
        sum%=mod;
        
        cout<<sum<<" ";
    }
    
    cout<<10<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1000003,INF=1<<30;
ll bik[MAX];

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
    
    int N;cin>>N;
    bik[0]=1;
    for(int i=1;i<=N;i++){
        bik[i]=bik[i-1]*i;
        bik[i]%=mod;
    }
    
    ll sum=bik[N];
    
    for(int i=N-1;i>=2;i--){
        sum+=bik[N]*rui(bik[i],mod-2)%mod*(bik[i]-1)%mod;
        sum%=mod;
    }
    
    cout<<sum<<endl;
}
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
    
    int N,Q;cin>>N;
    vector<ll> P(N+1),mul(N+1);
    set<int> SE;
    SE.insert(1);
    
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
    
    ll sum=0;
    
    for(int i=0;i<N;i++){
        sum+=mul[i];
        sum%=mod;
    }
    
    cout<<sum*rui(mul[N],mod-2)%mod<<endl;
    
}
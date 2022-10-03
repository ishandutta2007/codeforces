#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

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
    vector<ll> cnt(1000000,0),p(1000000);
    ll m=rui(N,mod-2);
    for(int i=0;i<N;i++){
        int K;cin>>K;
        for(int j=0;j<K;j++){
            int a;cin>>a;
            a--;
            cnt[a]++;
            p[a]+=m*rui(K,mod-2);
            p[a]%=mod;
        }
    }
    ll sum=0;
    for(int i=0;i<1000000;i++){
        sum+=p[i]*cnt[i]%mod*m%mod;
        sum%=mod;
    }
    
    cout<<sum<<endl;
}
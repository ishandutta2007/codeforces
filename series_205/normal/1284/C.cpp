#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll mod=1e9+7;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

/*-------------------------------------------*/

int n;
vector<ll> fact;

void f(int n){
    fact.resize(n+1);
    fact[0]=1;
    rep(i,n)fact[i+1]=fact[i]*(i+1)%mod;
}

int main(){
    cin>>n>>mod;
    f(n);

    ll ans=0;
    FOR(i,1,n+1){
        (ans+=(fact[i]*fact[n-i]%mod)*((n-i+1)*(n-i+1)%mod))%=mod;
    }
    cout<<ans<<endl;
}
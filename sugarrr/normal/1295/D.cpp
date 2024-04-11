//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
////////////////////////////

#define MAX_N (ll)2E7///
vector<ll>prime;
bool is_prime[MAX_N+1];
void precal(){
    rep(i,0,MAX_N)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,MAX_N){
        if(is_prime[i]){
            prime.pb(i);
            for(ll j=2*i;j<=MAX_N;j+=i)is_prime[j]=false;
        }
    }
}
vector<ll> fact(ll n){
    vector<ll>v;
    for(ll p:prime){
        if(p*p>n)break;
        ll c=0;
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)v.pb(p);//pc
    }
    if(n!=1){
        ll vsize=v.size();
        if(vsize>=1&&v[vsize-1]==n);
        else v.pb(n);
    }
    if(v.size()==0){
        v.pb(1);
    }
    return v;
}
/////////////////////////////////////////////////////

ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}

bool anspro(){
    ll a,b;cin>>a>>b;
    ll g=gcd(a,b);
    a/=g;b/=g;
    if(b==1){
        cout<<1<<endl;return 0;
    }
    vector<ll>v=fact(b);
    ll ans=0;
    ll vs=v.size();
    rep(i,0,(1<<vs)-1){
        ll k=1;
        ll c=0;
        rep(j,0,vs-1){
            if((i>>j)&1){
                k*=v[j];c++;
            }
        }
        if(c%2==0)ans+=b/k;
        else ans-=b/k;
    }
    cout<<ans<<endl;
    
    return 0;
}


int main(){fastio
    precal();
    /*
    rep(i,1,10){
        cout<<i<<":";
        vector<ll>v=fact(i);
        for(auto x:v)cout<<x<<" ";
        cout<<endl;
    }*/
    ll t;cin>>t;
    while(t--){
        anspro();
    }
    
    return 0;
}
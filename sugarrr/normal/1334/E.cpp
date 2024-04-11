//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
#define i_5 i_7-2

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////


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
vector<l_l> fact(ll n){
    vector<l_l>v;
    for(ll p:prime){
        if(p*p>n)break;
        ll c=0;
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)v.pb(l_l(p,c));//pc
    }
    if(n!=1){
        ll vsize=v.size();
        if(vsize>=1&&v[vsize-1].first==n)v[vsize-1].second++;
        else v.pb(l_l(n,1));
    }
    /*
    if(v.size()==0){
        v.pb(l_l(1,1));
    }*/
    return v;
}
/////////////////////////////////////////////////////


ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}


#define N 2000004
ll kai[N];
ll kai2[N];
void calc(){
    kai[0]=1;
    kai2[0]=1;
    rep(i,1,N-1){
        kai[i]=mod(kai[i-1]*i);
    }
    kai2[N-1]=po(kai[N-1],i_5);
    for(ll i=N-2;i>=0;i--){
        kai2[i]=mod(kai2[i+1]*(i+1));
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n==0)return 1;
    return mod(mod(kai[n]*kai2[n-k])*kai2[k]);
}

ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){fastio
    
    precal();calc();
    ll n;cin>>n;
    ll q;cin>>q;
    
    vector<ll>div;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            div.pb(i);
            if(i*i!=n)div.pb(n/i);
        }
    }
    SORT(div);
    ll divs=div.size();
    ll dp[divs];
    rep(i,0,divs-1){
        vector<l_l>v=fact(div[i]);
        dp[i]=1;
        ll sum=0;
        for(auto x:v){
            sum+=x.se;
            dp[i]=mod(dp[i]*kai2[x.se]);
        }
        dp[i]=mod(dp[i]*kai[sum]);
    }
    //rep(i,0,divs-1)cout<<dp[i]<<" ";cout<<endl;
    
    while(q--){
        ll a,b;cin>>a>>b;
        ll g=gcd(a,b);
        
        cout<<mod(dp[POSL(div,b/g)]*dp[POSL(div,a/g)])<<endl;
    }
    
    return 0;
}
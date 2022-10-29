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
///////////////////////////

#define N 1000005
#define Q 1000
bool prime[N];
vector<ll>p1,p2;
void calc(){
    rep(i,2,N-1)prime[i]=true;
    rep(i,2,N-1){
        if(prime[i]){
            for(ll j=i*2;j<=N-1;j+=i){
                prime[j]=false;
            }
        }
    }
    rep(i,2,N-1){
        if(prime[i]){
            if(i<=Q)p1.pb(i);
            p2.pb(i);
        }
    }
}

int main(){fastio
    calc();
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    shuffle(a,a+n,engine);
    //rep(i,0,n-1)cout<<a[i]<<" ";cout<<endl;
    ll ans=inf;
    for(auto x:p1){
        ll sum=0;
        rep(i,0,n-1){
            ll mod=a[i]%x;
            if(a[i]<x)sum+=x-mod;
            else sum+=min(mod,x-mod);
            if(sum>=ans)break;
        }
        Min(ans,sum);
    }
    //cout<<ans<<endl;
    
    vector<ll>kouho;
    rep(i,0,min(100,n-1)){
        rep(z,a[i]-2,a[i]+2){
            ll x=z;
            if(x<=Q)continue;
            for(auto y:p2){
                bool f=false;
                while(x>0&&x%y==0){
                    x/=y;
                    f=true;
                }
                if(f)if(y>Q)kouho.pb(y);
            }
            if(x!=1&&x>Q)kouho.pb(x);
        }
        
    }
    sort(kouho.begin(),kouho.end());
    kouho.erase(unique(kouho.begin(),kouho.end()),kouho.end());
    for(auto x:kouho){
        ll sum=0;
        rep(i,0,n-1){
            ll mod=a[i]%x;
            if(a[i]<x)sum+=x-mod;
            else sum+=min(mod,x-mod);
            if(sum>=ans)break;
        }
        Min(ans,sum);
    }
    cout<<ans<<endl;
    
    return 0;
}
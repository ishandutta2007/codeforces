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


ll n;
ll binary(ll l){
    ll ok=0,ng=n;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        ll sum=mid*(2*n-mid-1);
        if(l<=sum)ng=mid;
        else ok=mid;
    }
    return ok;
}
ll sum(ll mid){
    return mid*(2*n-mid-1);
}

bool anspro(){
    ll l,r;cin>>n>>l>>r;
    
    bool f=false;
    if(r==n*(n-1)+1){
        f=true;
        r--;
    }
    if(l>r){
        cout<<1<<endl;return 0;
    }
    
    ll okl=binary(l);
    ll okr=binary(r);
    ll resl=l-sum(okl);
    ll resr=r-sum(okr);
    okl++;okr++;
    vector<ll>ans;
    if(okl==okr){
        rep(i,resl,resr){
            if(i%2==1)ans.pb(okl);
            else ans.pb(i/2+(okl));
        }
    }else{
        rep(i,resl,(n-okl)*2){
            if(i%2==1)ans.pb(okl);
            else ans.pb(i/2+(okl));
        }
        rep(ok,okl+1,okr-1){
            rep(i,1,(n-ok)*2){
                if(i%2==1)ans.pb(ok);
                else ans.pb(i/2+(ok));
            }
        }
        rep(i,1,resr){
            if(i%2==1)ans.pb(okr);
            else ans.pb(i/2+(okr));
        }
        
    }
    if(f)ans.pb(1);
    
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    return 0;
}

int main(){fastio
    
    ll qu;cin>>qu;
    while(qu--){
        anspro();
    }
    
    return 0;
}
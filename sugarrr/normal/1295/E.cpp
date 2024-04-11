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

//
struct RMQRAQ{
    ll n;
    vector<ll>data,lazy;
    RMQRAQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
    }
    void eval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            data[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k];
                lazy[2*k+2]+=lazy[k];
            }
            lazy[k]=0;
        }
    }
    void add(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            lazy[k]+=x;
            eval(k,l,r);
        }else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            data[k]=min(data[2*k+1],data[2*k+2]);
        }
    }
    void add(ll a,ll b,ll x){add(a,b,x,0,0,n);}//[a,b)x
    ll query(ll a,ll b,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return inf;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)
};
//////////////////////////////////////////////////////

int main(){fastio
    ll n;cin>>n;
    ll p[n];rep(i,0,n-1)cin>>p[i];
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll pos[n+1];rep(i,0,n-1)pos[p[i]]=i;
    ll b[n];b[0]=a[0];
    rep(i,1,n-1)b[i]=a[i]+b[i-1];
    RMQRAQ u(n);
    rep(i,0,n-1){
        u.add(i,i+1,b[i]);
    }
    ll ans=min(a[0],a[n-1]);
    //rep(qq,0,n-1)cout<<u.query(qq,qq+1)<<" ";cout<<endl;
    rep(i,1,n){
        ll t=pos[i];
        u.add(t,n,-a[t]);
        u.add(0,t,a[t]);
        Min(ans,u.query(0,n-1));
       // rep(qq,0,n-1)cout<<u.query(qq,qq+1)<<" ";cout<<endl;
    }
    cout<<ans<<endl;
    
    return 0;
    
}
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

struct person{
    ll b;
    vector<ll>c;
};
bool comp(person x,person y){
    return x.b>y.b;
}
int main(){fastio
    ll n,p,k;cin>>n>>p>>k;
    person a[n];
    rep(i,0,n-1)cin>>a[i].b;
    rep(i,0,n-1){
        rep(j,0,p-1){
            ll x;cin>>x;a[i].c.pb(x);
        }
    }
    
    sort(a,a+n,[](auto lf,auto rg){
        return lf.b>rg.b;
    });
    //sort(a,a+n,comp);
    //rep(i,0,n-1)cout<<a[i].b<<" "<<a[i].c[0]<<" "<<a[i].c[1]<<endl;
    
    ll dp[2][1<<p];
    rep(i,0,(1<<p)-1)dp[0][i]=-inf;
    dp[0][0]=0;
    rep(i,0,n-1){
        rep(s,0,(1<<p)-1)dp[(i+1)&1][s]=dp[i&1][s];
        rep(s,0,(1<<p)-1){
            ll bit=0;rep(j,0,p-1)if((s>>j)&1)bit++;
            if(i+1<bit)continue;
            if(bit+k>=i+1)Max(dp[(i+1)&1][s],dp[i&1][s]+a[i].b);
            rep(j,0,p-1){
                ll x=1ll<<j;
                if(s&x){
                    Max(dp[(i+1)&1][s],dp[i&1][s-x]+a[i].c[j]);
                }
            }
        }
        /*
        rep(j,0,(1<<p)-1){
            cout<<dp[(i+1)&1][j]<<" ";
        }cout<<endl;*/
    }
    cout<<dp[n&1][(1<<p)-1]<<endl;
    //ll ans=0;
    
    
    return 0;
}
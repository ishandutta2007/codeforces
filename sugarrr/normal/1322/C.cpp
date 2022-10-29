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
#define endl "\n"

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
ll p1=1009;
//ll p2=1013;
ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}
bool ansp(){
    ll n,m;cin>>n>>m;
    ll c[n+1];rep(i,1,n)cin>>c[i];
    //vector<ll>v[n+1];
    l_l has1[n+1];
    //l_l has2[n+1];
    rep(i,1,n){
        has1[i]={0,i};
        //has2[i]={0,i};
    }
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        has1[b].fi+=po(p1,a);
        //has2[b].fi+=po(p2,a);
    }
    bool used[n+1];memset(used,false,sizeof(used));
    ll g=-1;
    sort(has1+1,has1+n+1);
    rep(i,1,n){
        if(has1[i].fi==0)continue;
        ll x=has1[i].se;
        ll sum=c[x];
        while(i<=n-1){
            ll y=has1[i+1].se;
            if(has1[i].fi==has1[i+1].fi){
                sum+=c[y];
                i++;
            }else{
                break;
            }
        }
        if(g==-1)g=sum;
        else g=gcd(g,sum);
    }
    cout<<g<<endl;
    return 0;
}

int main(){fastio
    ll que;cin>>que;
    while(que--){
        ansp();
    }
    
    return 0;
}
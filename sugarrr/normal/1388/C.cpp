//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 1024(TLE)
*/
 
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
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
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
#define endl "\n"  //
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;
//////////////////////////

#define N 100005
ll p[N];
ll h[N];
vector<ll>v[N];
ll sp[N];

void dfs1(ll id,ll par){
    sp[id]+=p[id];
    for(auto x:v[id]){
        if(x==par)continue;
        dfs1(x,id);
        sp[id]+=sp[x];
    }
}
ll a[N],b[N];
bool dfs2(ll id,ll par){
    ll sum=0;
    for(auto x:v[id]){
        if(x==par)continue;
        sum+=a[x];
        if(!dfs2(x,id))return false;
    }
    if(sum>a[id]){
        return false;
    }
    return true;
}

bool anspro(){
    ll n,m;cin>>n>>m;
    rep(i,1,n)cin>>p[i];
    rep(i,1,n)cin>>h[i];
    rep(i,1,n)v[i].clear();
    rep(zz,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    rep(i,1,n)sp[i]=0;
    dfs1(1,-1);
    rep(i,1,n){
        if(abs(h[i]-sp[i])%2==1){
            cout<<"NO"<<endl;
            return 0;
        }
        a[i]=(sp[i]+h[i])/2;
        b[i]=(sp[i]-h[i])/2;
        
    }
    /*
    rep(i,1,n)cout<<a[i]<<" ";cout<<endl;
    rep(i,1,n)cout<<b[i]<<" ";cout<<endl;
    rep(i,1,n)cout<<h[i]<<" ";cout<<endl;
    rep(i,1,n)cout<<sp[i]<<" ";cout<<endl;*/
    rep(i,1,n){
        if(a[i]>sp[i]){
            cout<<"NO"<<endl;
            return 0;
        }
        if(b[i]<0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    if(dfs2(1,-1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    return 0;
}

int main(){fastio
    
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}
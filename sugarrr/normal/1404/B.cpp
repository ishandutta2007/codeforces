
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
dd EPS=1E-12;
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

void ali(){
    cout<<"Alice"<<endl;
}
void bob(){
    cout<<"Bob"<<endl;
}

#define N 100005
ll d[N];

void cal(ll s,ll n,vector<ll>v[]){
    rep(i,1,n)d[i]=inf;
    queue<ll>q;q.push(s);
    d[s]=0;
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(d[x]==inf){
                d[x]=d[t]+1;
                q.push(x);
            }
        }
    }
}

bool anspro(){
    ll n,a,b,da,db;cin>>n>>a>>b>>da>>db;
    vector<ll>v[n+1];
    rep(i,1,n-1){
        ll x,y;cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if(da*2>=db){
        ali();return 0;
    }
    cal(a,n,v);
    if(d[b]<=da){
        ali();return 0;
    }
    ll mx=1;
    rep(i,1,n){
        if(d[i]>d[mx])mx=i;
    }
    cal(mx,n,v);
    mx=1;
    rep(i,1,n){
        if(d[i]>d[mx])mx=i;
    }
    if(d[mx]>da*2){
        bob();return 0;
    }else{
        ali();return 0;
    }
    
    return 0;
}

int main(){fastio
    
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}
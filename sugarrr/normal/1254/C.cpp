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
//#define endl "\n"  //
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


ll que(ll a,ll b,ll c,ll d){
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    fflush(stdout);
    ll t;cin>>t;
    return t;
}
void LAST(vector<ll>ans){
    cout<<0<<" ";
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    fflush(stdout);
}
#define N 10004
ll a[N];
bool c1(ll p,ll q){
    return a[p]<a[q];
}
bool c2(ll p,ll q){
    return a[p]>a[q];
}
int main(){fastio
    ll n;cin>>n;
    
    ll b[n+1];
    rep(i,3,n){
        a[i]=que(1,1,2,i);
        b[i]=que(2,1,2,i);
    }
    ll fp=-1,fn=-1;
    rep(i,3,n){
        if(b[i]==1){
            if(fp==-1||a[fp]<a[i])fp=i;
        }else{
            if(fn==-1||a[fn]<a[i])fn=i;
        }
    }
    ll c[n+1];
    vector<ll>ans={1};
    if(fp!=-1&&fn!=-1){
        rep(i,3,n){
            if(i==fp||i==fn)continue;
            c[i]=que(2,fn,fp,i);
        }
        
        vector<ll>v1,v2,v3,v4;
        rep(i,3,n){
            if(i==fn||i==fp)continue;
            if(b[i]==-1&&c[i]==1)v1.pb(i);
            else if(b[i]==-1&&c[i]==-1)v2.pb(i);
            else if(b[i]==1&&c[i]==-1)v3.pb(i);
            else if(b[i]==1&&c[i]==1)v4.pb(i);
        }
        sort(all(v1),[](ll p,ll q){
            return a[p]<a[q];
        });
        sort(all(v2),[](ll p,ll q){
            return a[p]>a[q];
        });
        sort(all(v3),[](ll p,ll q){
            return a[p]<a[q];
        });
        sort(all(v4),[](ll p,ll q){
            return a[p]>a[q];
        });
        for(auto x:v1)ans.pb(x);
        ans.pb(fn);
        for(auto x:v2)ans.pb(x);
        ans.pb(2);
        for(auto x:v3)ans.pb(x);
        ans.pb(fp);
        for(auto x:v4)ans.pb(x);
        LAST(ans);
    }else{
        
        bool revF=true;
        if(b[3]==1)revF=false;
        
        if(revF)fp=fn;
        rep(i,3,n){
            if(i==fp)continue;
            c[i]=que(2,1,fp,i);
        }
        vector<ll>v1,v2;
        rep(i,3,n){
            if(i==fp)continue;
            if(c[i]==1)v2.pb(i);
            else v1.pb(i);
        }
        sort(all(v1),[](ll p,ll q){
            return a[p]<a[q];
        });
        sort(all(v2),[](ll p,ll q){
            return a[p]>a[q];
        });
        if(revF){
            for(auto x:v1)ans.pb(x);
            ans.pb(fp);
            for(auto x:v2)ans.pb(x);
            ans.pb(2);
        }else{
            ans.pb(2);
            for(auto x:v1)ans.pb(x);
            ans.pb(fp);
            for(auto x:v2)ans.pb(x);
        }
        
        LAST(ans);
    }
    
    return 0;
}
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
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            //cout<<x<<"/"<<y;
            cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////



bool cal1(){
    ll n,k;cin>>n>>k;
    deque<ll>v(n),w(k);
    rep(i,0,n-1)cin>>v[i];
    rep(i,0,k-1)cin>>w[i];
    SORT(v);SORT(w);
    ll ans=0;
    ll pos=0;
    while(1){
        if(w[0]==1){
            ans+=2*(*v.rbegin());
            v.pop_back();
            w.pop_front();
        }else{
            break;
        }
    }
    n=v.size();
    k=w.size();
    rrep(i,k-1,0){
        ans+=v[pos];
        pos+=w[i]-1;
    }
    rep(i,0,k-1){
        ans+=v[n-i-1];
    }
    cout<<ans<<endl;
    
    
    return 0;
}

bool cal2(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n),b(k);
    rep(i,0,n-1)cin>>a[i];
    rep(i,0,k-1)cin>>b[i];
    SORT(a);SORT(b);
    ll pos=n-1;
    ll ans=0;
    rep(i,0,k-1){
        if(b[i]==1){
            ans+=a[pos]*2;
            pos--;
        }else{
            ans+=a[pos];
            pos--;
        }
    }
    pos=0;
    rrep(i,k-1,0){
        if(b[i]==1)break;
        ans+=a[pos];
        pos+=b[i]-1;
    }
    cout<<ans<<endl;
    
    
    return 0;
}

bool anspro(){
    cal2();
    return 0;
}

int main(){fastio
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}
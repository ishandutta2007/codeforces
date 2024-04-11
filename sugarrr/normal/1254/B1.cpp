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

ll cal(vector<ll>v){
    ll n=v.size();
    ll k=n/2;
    ll ans=0;
    rep(i,0,n-1){
        ans+=abs(v[i]-v[k]);
    }
    return ans;
}

int main(){fastio
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll sum=0;
    rep(i,0,n-1)sum+=a[i];
    if(sum==1){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll>v;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0){
            if(i!=1)v.pb(i);
            if(i*i!=sum)v.pb(sum/i);
        }
    }
    ll ans=inf;
    for(auto x:v){
        ll cnt=0;
        vector<ll>v;
        rep(i,0,n-1){
            if(a[i]==1){
                v.pb(i);
            }
            if(v.size()==x){
                cnt+=cal(v);
                v.clear();
            }
        }
       // cout<<x<<" "<<cnt<<endl;
        chmin(ans,cnt);
    }
    cout<<ans<<endl;
    
    return 0;
}
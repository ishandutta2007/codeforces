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



bool anspro(){
    ll n,k;cin>>n>>k;
    ll l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    if(l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    ll res=0,val=0;
    ll motoval=0;
    
    if(r1<l2){
        res=l2-r1;
    }else{
        motoval=min(r2,r1)-l2;
        k-=motoval*n;
    }
    val=max(r2,r1)-l1-motoval;
    if(k<=0){
        cout<<0<<endl;
        return 0;
    }
    ll ans=inf;
    rep(i,0,n){
        if(1<=i&&i<=n){
            ll K=k;
            ll sum=(res+val)*i;
            K-=val*i;
            if(K>0)sum+=K*2;
            chmin(ans,sum);
        }
        if(i<n){
            ll K=k;
            ll sum=(res+val)*i;
            K-=val*i;
            if(0<K&&K<=val){
                sum+=res+K;
                chmin(ans,sum);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

int main(){fastio
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}
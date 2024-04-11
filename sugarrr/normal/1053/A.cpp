
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
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
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
            cout<<x<<"/"<<y<<endl;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////

void no(){
    cout<<"NO";
    exit(0);
}
ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){fastio
    ll n,m,k;cin>>n>>m>>k;
    if((2*n*m)%k==0){
        ll g1=gcd(2*n,k);
        ll g2=k/g1;
        ll x=2*n/g1;
        ll y=m/g2;
        if(x>n){
            x/=2;
            y*=2;
        }
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<x<<" 0"<<endl;
        cout<<"0 "<<y<<endl;
        
    }else{
        no();
    }
    
    return 0;
}
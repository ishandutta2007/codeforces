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
////////////////////////////


int main(){fastio
    string s;cin>>s;
    ll n=s.size();
    ll cou[26][26];memset(cou,0,sizeof(cou));
    ll a[26];memset(a,0,sizeof(a));
    rep(p,0,n-1){
        ll k=s[p]-'a';
        rep(j,0,25){
            cou[j][k]+=a[j];
        }
        a[k]++;
        //rep(i,0,25)cout<<a[i]<<" ";cout<<endl;
    }
    /*
    rep(i,0,25)cout<<a[i]<<" ";cout<<endl;
    rep(i,0,25){
        rep(j,0,25)cout<<cou[i][j]<<" ";cout<<endl;
    }*/
    ll ans=0;
    rep(i,0,25)rep(j,0,25)Max(ans,cou[i][j]);
    rep(i,0,25)Max(ans,a[i]);
    cout<<ans<<endl;
    
    return 0;
}
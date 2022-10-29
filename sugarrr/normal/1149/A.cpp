#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
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
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////


int main(){fastio
    ll n;cin>>n;
    ll a=0,b=0;
    rep(i,0,n-1){
        ll c;cin>>c;
        if(c==1)a++;
        else b++;
    }
    if(a==0){
        rep(i,0,n-1)cout<<2<<" ";
        cout<<endl;
        return 0;
    }
    if(b==0){
        rep(i,0,n-1)cout<<1<<" ";
        cout<<endl;
        return 0;
    }
    cout<<2<<" "<<1<<" ";
    a--;b--;
    rep(i,1,b)cout<<2<<" ";
    rep(i,1,a)cout<<1<<" ";
    cout<<endl;
    
    
    return 0;
}
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
////////////////////////////

bool anspro(){
    ll n,k1,k2;cin>>n>>k1>>k2;
    ll a[k1];rep(i,0,k1-1)cin>>a[i];
    ll b[k2];rep(i,0,k2-1)cin>>b[i];
    sort(a,a+k1);sort(b,b+k2);
    //rep(i,0,k1-1)cout<<a[i]<<" ";cout<<endl;
    //rep(i,0,k2-1)cout<<b[i]<<" ";cout<<endl;
    if(a[k1-1]<b[k2-1]){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}


int main(){fastio
    
    ll t;cin>>t;
    while(t--){
        anspro();
    }
    
    return 0;
}
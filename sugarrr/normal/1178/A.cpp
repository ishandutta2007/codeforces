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

int main(){
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll sum=0;rep(i,0,n-1)sum+=a[i];
    vector<ll>v;
    v.pb(1);
    ll vsum=a[0];
    rep(i,1,n-1){
        if(a[0]>=a[i]*2){
            v.pb(i+1);
            vsum+=a[i];
        }
    }
    if(vsum*2>sum){
        cout<<v.size()<<endl;
        for(auto x:v)cout<<x<<" ";
    }else{
        cout<<0<<endl;
    }
    
    return 0;
}
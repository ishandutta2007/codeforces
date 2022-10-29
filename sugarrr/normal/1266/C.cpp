
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




int main(){fastio
    
    ll r,c;cin>>r>>c;
    if(r==1&&c==1){
        cout<<0<<endl;return 0;
    }
    if(c==1){
        rep(i,1,r){
            cout<<i+1<<endl;
        }
        return 0;
    }
    ll a[r+1][c+1];
    rep(i,1,r){
        rep(j,1,c){
            ll k=r+j;
            a[i][j]=i*k;
        }
    }
    rep(i,1,r){
        rep(j,1,c){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
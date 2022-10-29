//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////


ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}

ll M=4005;


int main(){fastio
    ll n,k;cin>>n>>k;
    if(k==1){cout<<0<<endl;return 0;}
    ll h[n];rep(i,0,n-1)cin>>h[i];
    ll dp[n+1][M*2+1];
    memset(dp,0,sizeof(dp));
    dp[0][M]=1;
    rep(i,0,n-1){
        bool f=h[i]==h[(i+1)%n];
        if(f){
            rep(j,0,2*M)Add(dp[i+1][j],mod(k*dp[i][j]));
        }else{
            rep(j,0,2*M){
                Add(dp[i+1][j],mod((k-2)*dp[i][j]));
                if(j+1<=2*M)Add(dp[i+1][j+1],dp[i][j]);
                if(j-1>=0)Add(dp[i+1][j-1],dp[i][j]);
            }
        }
    }
    ll ans=0;
    rep(j,M+1,2*M)Add(ans,dp[n][j]);
    cout<<ans<<endl;
    
    return 0;
}
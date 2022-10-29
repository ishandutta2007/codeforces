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


int main(){fastio
    string s,t;cin>>s>>t;
    ll n=s.size(),m=t.size();
    ll dp[n][n];memset(dp,0,sizeof(dp));
    rep(len,0,n-1){
        if(len==0){
            rep(j,0,n-1){
                if(j>=m||s[len]==t[j]){
                    dp[j][j]=1;
                }
            }
        }else{
            rep(i,0,n-1){
                ll j=i+len;
                if(j>=n)break;
                if(i>=m||s[len]==t[i])Add(dp[i][j],dp[i+1][j]);
                if(j>=m||s[len]==t[j])Add(dp[i][j],dp[i][j-1]);
            }
        }
    }
    /*
    rep(i,0,n-1){
        rep(j,0,n-1)cout<<dp[i][j]<<" ";cout<<endl;
    }*/
    ll ans=0;
    rep(j,m-1,n-1)Add(ans,dp[0][j]);
    ans=mod(ans*2);
    cout<<ans<<endl;
    
    return 0;
}
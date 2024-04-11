#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

#define N 34
bool anspro(){
    ll d,m;cin>>d>>m;
    if(m==1){
        cout<<0<<endl;return 0;
    }
    ll cnt[N];memset(cnt,0,sizeof(cnt));
    ll val=2;
    cnt[0]=1;
    rep(i,1,N-1){
        val*=2;
        cnt[i]=(cnt[i-1]*2)%m;
        if(d<val){
            val/=2;
            cnt[i]=d-val+1;
            break;
        }
    }
    //rep(i,0,N-1)cout<<cnt[i]<<" ";cout<<endl;
    ll dp[N+1];memset(dp,0,sizeof(dp));
    dp[0]=1;
    rep(i,1,N-1){
        rep(j,0,i-1){
            dp[i]=(dp[i]+(dp[j]*cnt[i-1]))%m;
        }
    }
    //rep(i,0,N-1)cout<<dp[i]<<" ";cout<<endl;cout<<endl;
    ll ans=0;
    rep(i,1,N-1)ans=(ans+dp[i])%m;
    cout<<ans%m<<endl;
    return 0;
}

int main(){fastio
    
    ll qu;cin>>qu;
    while(qu--){
        anspro();
    }
    
    
    return 0;
}
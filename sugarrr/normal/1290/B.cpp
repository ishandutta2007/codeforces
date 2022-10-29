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
    ll a[n+1][26];memset(a,0,sizeof(a));
    rep(i,0,n-1){
        rep(j,0,25)a[i+1][j]=a[i][j];
        a[i+1][s[i]-'a']++;
    }
    ll q;cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        bool flag=true;
        if(l==r){
            flag=true;
        }else{
            ll c[26];
            rep(i,0,25){
                c[i]=a[r][i]-a[l-1][i];
            }
            ll re=0;
            rep(i,0,25)if(c[i]!=0)re++;
            if(re==1)flag=false;
            else if(re==2){
                if(s[l-1]==s[r-1])flag=false;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
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
bool anspro(){
    string s,t;cin>>s>>t;
    bool cs[26][2];memset(cs,false,sizeof(cs));
    rep(i,0,s.size()-1){
        cs[s[i]-'a'][0]=true;
    }
    rep(i,0,t.size()-1){
        cs[t[i]-'a'][1]=true;
    }
    rep(i,0,25){
        if(!cs[i][0]&&cs[i][1]){
            cout<<-1<<endl;return 0;
        }
    }
    vector<ll>v[26];
    rep(i,0,s.size()-1){
        v[s[i]-'a'].pb(i);
    }
    ll ans=1,pos=0;
    rep(i,0,t.size()-1){
        ll k=t[i]-'a';
        ll p=lower_bound(v[k].begin(),v[k].end(),pos)-v[k].begin();
        if(p==v[k].size()){
            ans++;
            pos=v[k][0]+1;
        }else{
            pos=v[k][p]+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
int main(){fastio
    
    ll t;cin>>t;
    while(t--){
        anspro();
    }
    
    return 0;
}
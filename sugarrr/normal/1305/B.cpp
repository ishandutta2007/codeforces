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
///////////////////////////


int main(){fastio
    string s;cin>>s;
    ll n=s.size();
    ll l=0,r=n-1;
    vector<ll>ans;
    while(1){
        bool flag=true;
        while(l<r&&s[l]==')')l++;
        while(l<r&&s[r]=='(')r--;
        if(l<r&&s[l]=='('&&s[r]==')'){
            flag=false;
            ans.pb(l);ans.pb(r);
            l++;r--;
        }
        
        if(flag)break;
    }
    if(ans.size()==0){
        cout<<0<<endl;return 0;
    }
    cout<<1<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto x:ans)cout<<x+1<<" ";cout<<endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll k;cin>>k;
    string s,t;cin>>s>>t;
    ll a[k],b[k];
    rep(i,0,k-1){
        a[i]=(s[i]-'a');
        b[i]=(t[i]-'a');
    }
    //rep(i,0,k-1)cout<<a[i]<<" ";cout<<endl;
    //rep(i,0,k-1)cout<<b[i]<<" ";cout<<endl;
    
    
    ll sum[k];
    rep(i,0,k-1){
        sum[i]=a[i]+b[i];
    }
    for(ll i=k-1;i>=1;i--){
        ll res=sum[i]/26;
        sum[i]-=26*res;
        sum[i-1]+=res;
    }
    string ans;
    ll res=0;
    rep(i,0,k-1){
        res*=26;
        res+=sum[i];
        ans+=('a'+res/2);
        res%=2;
    }
    cout<<ans<<endl;
    
    return 0;
}
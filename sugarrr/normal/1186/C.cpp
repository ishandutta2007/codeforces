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


int main(){fastio
    
    string s,t;cin>>s>>t;
    ll n=s.size();
    ll sum[n+1][2];
    memset(sum,0,sizeof(sum));
    rep(i,0,n-1){
        rep(j,0,1)sum[i+1][j]=sum[i][j];
        if(s[i]=='0')sum[i+1][0]++;
        else sum[i+1][1]++;
    }
    ll a=0,b=0;
    ll ts=t.size();
    rep(i,0,ts-1){
        if(t[i]=='0')a++;
        else b++;
    }
    ll ans=0;
    for(ll i=0;i+ts<=n;i++){
        ll t=sum[i+a][1]-sum[i][1];
        t+=sum[i+ts][0]-sum[i+a][0];
        if(t%2==0)ans++;
        //cout<<t<<" ";
    }
    cout<<ans<<endl;
    
    
    return 0;
}
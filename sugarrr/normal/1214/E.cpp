#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
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
    ll n;
    scanf("%lld",&n);
    l_l k[n+1];
    rep(i,1,n){
        scanf("%lld",&k[i].first);
        k[i].second=i*2;
    }
    sort(k+1,k+n+1);
    reverse(k+1,k+n+1);
    
    ll a[2*n+1];
    memset(a,0,sizeof(a));
    vector<l_l>ans;
    rep(i,1,n){
        a[i]=k[i].second-1;
        if(i>=2){
            ans.pb(l_l(a[i-1],a[i]));
        }
    }
    ll last=n;
    rep(i,1,n){
        if(last-i+1==k[i].first){
            last++;
            a[last]=k[i].second;
            ans.pb(l_l(k[i].second,a[last-1]));
        }else{
            ll pos=i+k[i].first-1;
            ans.pb(l_l(a[pos],k[i].second));
        }
    }
    rep(i,0,2*n-2){
        printf("%lld %lld\n",ans[i].first,ans[i].second);
    }
    
    
    
    return 0;
}
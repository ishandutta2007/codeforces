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

int main(){
    string s;cin>>s;
    ll n=s.size();
    ll pos=0;
    while(pos<=n-1){
        if(s[pos]=='v')break;
        else pos++;
    }
    vector<ll>v;
    while(pos<=n-1){
        ll c=1;
        while(pos<=n-2){
            if(s[pos]==s[pos+1]){
                c++;
                pos++;
            }else{
                break;
            }
        }
        v.pb(c);
        pos++;
    }
    //for(auto x:v)cout<<x<<" ";
    ll vs=v.size();
    if(vs%2==0){
        v.pb(0);
        vs++;
    }
    ll k=(vs+1)/2;
    ll a[k];
    for(ll i=0;i<=vs;i+=2){
        a[i/2]=max(v[i]-1,0);
    }
    ll dp1[k],dp2[k];
    dp1[0]=a[0];
    rep(i,1,k-1){
        dp1[i]=dp1[i-1]+a[i];
    }
    dp2[k-1]=a[k-1];
    for(ll i=k-2;i>=0;i--){
        dp2[i]=dp2[i+1]+a[i];
    }
    ll ans=0;
    rep(i,0,k-2){
        ll p=v[2*i+1];
        ans+=p*dp1[i]*dp2[i+1];
    }
    cout<<ans<<endl;
    
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-9;
////////////////////////////////////////


int main(){
    ll n,m,k;cin>>n>>m>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    ll ans=0;
    ll p=m/(k+1);
    ll q=m-p;
    ans=q*a[n-1]+p*a[n-2];
    cout<<ans<<endl;
    return 0;
}
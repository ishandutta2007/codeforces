
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////

void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    ll s=m*k;
    l_l a[n];
    rep(i,0,n-1){
        cin>>a[i].first;a[i].second=i+1;
    }
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0;
    vector<ll>pos;
    rep(i,0,s-1){
        ans+=a[i].first;
        pos.pb(a[i].second);
    }
    sort(pos.begin(),pos.end());
    cout<<ans<<endl;
    for(ll i=m-1;i<=s-2;i+=m){
        cout<<pos[i]<<" ";
    }
    
    return 0;
}
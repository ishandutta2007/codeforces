
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

struct ex{
    ll a,b,c;
};

#define N 200005
ll cou[N];
int main(){fastio
    ll n;cin>>n;
    ll a[n+1];
    rep(i,1,n){
        cin>>a[i];
        cou[a[i]]++;
    }
    ll ma=0,man=0;
    rep(i,0,N){
        if(cou[i]>ma){
            ma=cou[i];
            man=i;
        }
    }
    vector<ll>p;
    rep(i,1,n){
        if(a[i]==man)p.pb(i);
    }
    vector<ex>manu;
    for(ll i=p[0]-1;i>=1;i--){
        if(a[i]<a[p[0]]){
            manu.pb(ex{1,i,i+1});
        }else if(a[i]>a[p[0]]){
            manu.pb(ex{2,i,i+1});
        }
    }
    for(ll i=p[0]+1;i<=n;i++){
        if(a[i]<a[p[0]]){
            manu.pb(ex{1,i,i-1});
        }else if(a[i]>a[p[0]]){
            manu.pb(ex{2,i,i-1});
        }
    }
    cout<<manu.size()<<endl;
    for(auto x:manu){
        cout<<x.a<<" "<<x.b<<" "<<x.c<<endl;
    }
    
    return 0;
}
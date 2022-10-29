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

#define N 200005
ll n,m;
vector<ll>v[N];
ll p[N];ll k;
ll dis[N];
vector<ll>rev[N];
int main(){
    cin>>n>>m;
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[b].pb(a);
        rev[a].pb(b);
    }
    cin>>k;
    rep(i,0,k-1)cin>>p[i];
    rep(i,1,n)dis[i]=inf;
    dis[p[k-1]]=0;
    queue<ll>q;q.push(p[k-1]);
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(dis[x]==inf){
                dis[x]=dis[t]+1;
                q.push(x);
            }
        }
    }
    //rep(i,1,n)cout<<dis[i]<<" ";cout<<endl;
    ll ans=0,add=0;
    rep(i,0,k-2){
        ll s=p[i],t=p[i+1];
        if(dis[s]<=dis[t]){
            ans++;
        }else{
            bool flag=false;
            for(auto x:rev[s]){
                if(x!=t&&dis[s]>dis[x]){
                    flag=true;break;
                }
            }
            if(flag)add++;
        }
    }
    add+=ans;
    cout<<ans<<" "<<add<<endl;
    return 0;
}
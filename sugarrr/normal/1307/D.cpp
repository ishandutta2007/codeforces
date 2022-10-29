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
////////////////////////////

#define N 200005
ll n,m,k;
vector<ll>v[N];

vector<l_l>compp(vector<l_l>v){
    vector<l_l>res;
    sort(v.begin(),v.end());
    ll vs=v.size();
    ll ma=-inf;
    for(ll i=vs-1;i>=0;i--){
        if(v[i].se>ma){
            res.pb(v[i]);
            ma=v[i].se;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<ll>dijk(ll s){
    queue<ll>q;
    ll dis[n+1];rep(i,0,n)dis[i]=inf;
    q.push(s);dis[s]=0;
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(dis[x]==inf){
                dis[x]=dis[t]+1;
                q.push(x);
            }
        }
    }
    
    vector<ll>res;
    rep(i,1,n)res.pb(dis[i]);
    return res;
}
struct box{
    ll x,y,dis;
};
bool comp(box a,box b){
    return a.dis<b.dis;
}

int main(){fastio
    cin>>n>>m>>k;
    ll a[k];rep(i,0,k-1)cin>>a[i];
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    vector<box>d(k);
    vector<ll>res=dijk(1);
    rep(j,0,k-1){
        ll i=a[j];
        d[j].x=res[i-1];
    }
    res=dijk(n);
    ll ansinit=res[0];
    rep(j,0,k-1){
        ll i=a[j];
        d[j].y=res[i-1];
    }
    rep(j,0,k-1)d[j].dis=d[j].y-d[j].x;
    sort(d.begin(),d.end(),comp);
    //for(auto x:d)cout<<x.x<<" "<<x.y<<endl;cout<<endl;
    ll ma[k];
    for(ll i=k-1;i>=1;i--){
        if(i==k-1)ma[i]=d[i].x;
        else{
            ma[i]=max(ma[i+1],d[i].x);
        }
    }
    ll ans=0;
    rep(i,0,k-2){
        Max(ans,d[i].y+ma[i+1]+1);
    }
    Min(ans,ansinit);
    cout<<ans<<endl;
    
    
    return 0;
}
/*
 11 11 3
 2 9 10
 1 2
 2 3
 3 4
 4 5
 3 7
 7 6
 7 8
 8 9
 9 6
 6 10
 9 11
 */
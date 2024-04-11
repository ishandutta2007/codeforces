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

#define N 1005
ll n;
vector<ll> v[N];
bool used[N];
void print(ll x){
    cout<<"! "<<x<<endl;
    fflush(stdout);
}
ll ask(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    ll c;cin>>c;
    return c;
}

int main(){fastio
    cin>>n;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);v[b].pb(a);
    }
    ll r=1;
    while(1){
        ll dis[n+1];rep(i,1,n)dis[i]=-1;
        dis[r]=0;
        queue<ll>q;q.push(r);
        while(!q.empty()){
            ll t=q.front();q.pop();
            for(auto x:v[t]){
                if(used[x])continue;
                if(dis[x]!=-1)continue;
                dis[x]=dis[t]+1;
                q.push(x);
            }
        }
        rep(i,1,n){
            if(dis[i]>dis[r])r=i;
        }
        rep(i,1,n)dis[i]=-1;
        dis[r]=0;
        q.push(r);
        while(!q.empty()){
            ll t=q.front();q.pop();
            for(auto x:v[t]){
                if(used[x])continue;
                if(dis[x]!=-1)continue;
                dis[x]=dis[t]+1;
                q.push(x);
            }
        }
        ll r2=1;
        rep(i,1,n){
            if(dis[i]>dis[r2])r2=i;
        }
        if(r==r2){
            print(r);return 0;
        }
        ll r3=ask(r,r2);
        if(r==r3||r2==r3){
            print(r3);return 0;
        }
        q.push(r2);q.push(r);
        used[r2]=true;
        used[r]=true;
        while(!q.empty()){
            ll t=q.front();q.pop();
            for(auto x:v[t]){
                if(r3==x)continue;
                if(used[x])continue;
                used[x]=true;
                q.push(x);
            }
        }
        r=r3;
        ll count=0;
        rep(i,1,n)if(used[i]==false)count++;
        if(count==1){
            rep(i,1,n)if(used[i]==false){
                print(i);return 0;
            }
        }
    }
    return 0;
}
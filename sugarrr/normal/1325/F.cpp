#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
#define endl "\n"
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

#define N 100005
ll n,m;
vector<ll>v[N];
vector<ll>chi[N];
ll pa[N];
ll dis[N];
void dfs(ll id){
    for(auto x:v[id]){
        if(dis[x]!=0)continue;
        chi[id].pb(x);
        pa[x]=id;
        dis[x]=dis[id]+1;
        dfs(x);
    }
}

int main(){fastio
    cin>>n>>m;
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll sta=3;
    pa[sta]=0;dis[sta]=1;
    dfs(sta);
    //rep(i,1,n)cout<<dis[i]<<" ";
    ll sq=(ll)sqrt(n);
    if(sq*sq!=n)sq++;
    rep(i,1,n){
        for(auto x:v[i]){
            ll d1=dis[i],d2=dis[x];
            
            if(abs(d1-d2)>=sq-1){
                if(d1>d2)swap(i,x);
                vector<ll>ans;ans.pb(x);
                while(i!=x){
                    x=pa[x];
                    ans.pb(x);
                }
                cout<<2<<endl<<ans.size()<<endl;
                for(auto y:ans)cout<<y<<" ";
                return 0;
            }
        }
    }
    vector<ll>ans;
    bool used[n+1];memset(used,false,sizeof(used));
    vector<l_l>vd;
    rep(i,1,n){
        vd.pb(l_l(-dis[i],i));
    }
    SORT(vd);
    for(auto xx:vd){
        ll x=xx.se;
        if(used[x])continue;
        used[x]=true;
        ans.pb(x);
        for(auto y:v[x])used[y]=true;
    }
    cout<<1<<endl;
    rep(i,0,sq-1)cout<<ans[i]<<" ";
    
    return 0;
}

/*
 10 10
 1 2
 2 3
 3 4
 2 5
 5 6
 6 2
 1 7
 7 8
 8 9
 */
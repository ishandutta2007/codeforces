//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////




vector<ll> Maxiv[100001];

struct MaxiNode{
    ll par;
    vector<ll> chi;
};
MaxiNode maxinode[100001];
void Maxiinit_par(ll x){
    rep(i,0,Maxiv[x].size()-1){
        if(Maxiv[x][i]==maxinode[x].par){
            continue;
        }
        maxinode[Maxiv[x][i]].par=x;
        maxinode[x].chi.pb(Maxiv[x][i]);
        Maxiinit_par(Maxiv[x][i]);
    }
}

int main(){fastio
    ll n;cin>>n;
    ll a[n-1],b[n-1];
    rep(i,0,n-2)cin>>a[i]>>b[i];
    
    rep(i,0,n-2){
        Maxiv[a[i]].pb(b[i]);
        Maxiv[b[i]].pb(a[i]);
    }
    ll Maxip=0;
    rep(i,1,n){
        if(Maxiv[i].size()>=2){
            Maxip=i;
            break;
        }
    }
    maxinode[Maxip].par=Maxip;
    Maxiinit_par(Maxip);
    ll Maxi=0;
    rep(i,1,n){
        ll maxisum=0;
        rep(j,0,(ll)Maxiv[i].size()-1){
            if(maxinode[Maxiv[i][j]].chi.size()==0){
                maxisum++;
            }
        }
        if(maxisum<=1){
            Maxi+=maxinode[i].chi.size();
        }else{
            Maxi+=(maxinode[i].chi.size()+1-maxisum);
        }
    }
    vector<ll>v[n+1];
    rep(i,0,n-2){
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    ll root=1;
    rep(i,1,n){
        if(v[i].size()>=2){
            root=i;break;
        }
    }
    ll dep[n+1];memset(dep,-1,sizeof(dep));
    queue<ll>q;q.push(root);
    dep[root]=0;
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:v[t]){
            if(dep[x]==-1){
                dep[x]=dep[t]+1;
                q.push(x);
            }
        }
    }
    bool f[2];memset(f,false,sizeof(f));
    rep(i,1,n){
        if(v[i].size()==1){
            f[dep[i]%2]=true;
        }
    }
    ll minans=3;
    if(f[0]==false||f[1]==false)minans=1;
    cout<<minans<<" "<<Maxi<<endl;
    
    return 0;
}
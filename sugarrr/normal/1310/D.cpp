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

unsigned int rnd(){
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
#include <chrono>
//auto end=chrono::system_clock::now();
//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0);//
//cerr<<"loop: "<<loopcount<<endl;


int main(){fastio
    auto start=chrono::system_clock::now();
    ll loopcount=0;
    ll n,k;cin>>n>>k;
    ll a[n][n];rep(i,0,n-1)rep(j,0,n-1)cin>>a[i][j];
    ll ans=inf;
    while(1){
        auto end=chrono::system_clock::now();
        double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()/ 1000000.0);
        if(time>2.5)break;
        vector<ll>v[2];
        v[0].pb(0);
        rep(j,1,n-1){
            v[rnd()&1].pb(j);
        }
        ll dp[k+1][n];rep(i,0,k)rep(j,0,n-1)dp[i][j]=inf;
        dp[0][0]=0;
        rep(i,1,k){
            rep(j,0,n-1){
                for(auto x:v[i&1]){
                    Min(dp[i][x],dp[i-1][j]+a[j][x]);
                }
            }
        }
        Min(ans,dp[k][0]);
        loopcount++;
    }
    cerr<<"loop:"<<loopcount<<endl;
    cout<<ans<<endl;
    
    return 0;
}
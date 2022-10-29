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



int main(){fastio
    ll n,m;cin>>n>>m;
    ll a[n][m];rep(i,0,n-1)rep(j,0,m-1)cin>>a[i][j];
    ll ok=0,ng=inf;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        set<ll>s;
        rep(i,0,n-1){
            ll k=0;
            rep(j,0,m-1){
                if(a[i][j]>=mid)k+=1ll<<j;
            }
            s.insert(k);
        }
        bool flag=false;
        for(auto x:s){
            for(auto y:s){
                if((x|y)==(1ll<<m)-1){
                    flag=true;break;
                }
            }
        }
        if(flag)ok=mid;
        else ng=mid;
    }
    ll a1=-1,a2=-1;
    set<ll>s;
    ll p[n];
    rep(i,0,n-1){
        ll k=0;
        rep(j,0,m-1){
            if(a[i][j]>=ok)k+=1ll<<j;
        }
        s.insert(k);
        p[i]=k;
    }
    for(auto x:s){
        for(auto y:s){
            if((x|y)==(1ll<<m)-1){
                rep(i,0,n-1){
                    if(p[i]==x)a1=i+1;
                    if(p[i]==y)a2=i+1;
                }
                cout<<a1<<endl<<a2<<endl;
                return 0;
            }
        }
    }
    
    return 0;
}
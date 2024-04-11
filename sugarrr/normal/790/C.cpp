//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 1024(TLE)
*/
 
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
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
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
//#define endl "\n"  //
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;
//////////////////////////


int main(){fastio
    ll n;cin>>n;
    string s;cin>>s;
    vector<ll>a,b,c;
    rep(i,0,n-1){
        if(s[i]=='V')a.pb(i);
        else if(s[i]=='K')b.pb(i);
        else c.pb(i);
    }
    ll as=a.size(),bs=b.size(),cs=c.size();
    ll dp[n+1][as+1][bs+1][2];
    rep(i,0,n)rep(j,0,as)rep(k,0,bs)rep(l,0,1)dp[i][j][k][l]=inf;
    dp[0][0][0][0]=0;
    rep(i,0,n-1){
        rep(j,0,as){
            rep(k,0,bs){
                ll l=i-j-k;
                if(l<0)continue;
                if(j<as){
                    ll add=0;
                    add+=max(POSL(a,a[j])-j,0);
                    add+=max(POSL(b,a[j])-k,0);
                    add+=max(POSL(c,a[j])-l,0);
                    
                    chmin(dp[i+1][j+1][k][1],dp[i][j][k][0]+add);
                    chmin(dp[i+1][j+1][k][1],dp[i][j][k][1]+add);
                }
                if(k<bs){
                    ll add=0;
                    add+=max(POSL(a,b[k])-j,0);
                    add+=max(POSL(b,b[k])-k,0);
                    add+=max(POSL(c,b[k])-l,0);
                    chmin(dp[i+1][j][k+1][0],dp[i][j][k][0]+add);
                }
                if(l<cs){
                    ll add=0;
                    add+=max(POSL(a,c[l])-j,0);
                    add+=max(POSL(b,c[l])-k,0);
                    add+=max(POSL(c,c[l])-l,0);
                    chmin(dp[i+1][j][k][0],dp[i][j][k][0]+add);
                    chmin(dp[i+1][j][k][0],dp[i][j][k][1]+add);
                }
            }
        }
    }
    /*
    rep(i,0,n){
        rep(l,0,1){
            cout<<"L="<<l<<endl;
            rep(j,0,as){
                rep(k,0,bs){
                        if(dp[i][j][k][l]>=inf/2)cout<<""<<" ";
                        else cout<<dp[i][j][k][l]<<" ";
                }cout<<endl;
            }cout<<endl;
        }cout<<endl;
    }cout<<endl;*/
    
    ll ans=inf;
    rep(l,0,1)chmin(ans,dp[n][as][bs][l]);
    cout<<ans<<endl;
    
    return 0;
}
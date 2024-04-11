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
#define endl "\n"  //
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

ll dx[8]={0,-1,-1,-1,0,1,1,1};
ll dy[8]={1,1,0,-1,-1,-1,0,1};

struct item{
    l_l pos;
    ll dir;
    bool const operator<(const item op)const{
        if(pos==op.pos)return dir<op.dir;
        return pos<op.pos;
    }
    bool const operator==(const item op)const{
        if(pos==op.pos&&dir==op.dir)return true;
        return false;
    }
};

int main(){fastio
    ll N=200;
  //  ll N=15;
    bool a[N*2][N*2];memset(a,false,sizeof(a));
    ll n;cin>>n;
    vector<item>dp;
    vector<item>ep;
    dp.pb({{N,N},0});
    while(n--){
        ll L;cin>>L;
        for(auto x:dp){
            ll nx=x.pos.fi,ny=x.pos.se;
            rep(z,1,L){
                nx+=dx[x.dir];
                ny+=dy[x.dir];
                a[nx][ny]=true;
            }
            for(ll dd=-1;dd<=1;dd+=2){
                ll di=(x.dir+16+dd)%8;
                ep.pb({{nx,ny},di});
            }
        }
        SORT(ep);ERASE(ep);
        dp=ep;
        ep.clear();
    }
    /*
    rep(i,0,N*2-1){
        rep(j,0,2*N-1){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;*/
    ll ans=0;
    rep(i,0,N*2-1)rep(j,0,2*N-1)if(a[i][j])ans++;
    cout<<ans<<endl;
    
    return 0;
}
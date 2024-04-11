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

#define N 100
ll ns;
vector<ll>np;
bool anspro(){
    ll n;cin>>n;
    rep(i,0,ns-1){
        rep(j,i+1,ns-1){
            rep(k,j+1,ns-1){
                ll sum=np[i]+np[j]+np[k];
                ll ad=n-sum;
                if(sum<n&&ad!=np[i]&&ad!=np[j]&&ad!=np[k]){
                    cout<<"YES"<<endl;
                    cout<<np[i]<<" "<<np[j]<<" "<<np[k]<<" "<<ad<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
bool pri[N];
vector<ll>p;

int main(){fastio
    for(ll i=2;i<=N-1;i++){
        if(pri[i])continue;
        p.pb(i);
        for(ll j=i;j<=N-1;j+=i){
            pri[j]=true;
        }
    }
    ll ps=p.size();
    rep(i,0,ps-1){
        rep(j,i+1,ps-1){
            ll c=p[i]*p[j];
            if(c<=N-1)np.pb(c);
        }
    }
    SORT(np);ERASE(np);
    ns=np.size();
    
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}
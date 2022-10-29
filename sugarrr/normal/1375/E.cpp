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
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            //cout<<x<<"/"<<y;
            cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////



#define N 200005
ll n;
ll a[N];
bool comp(l_l x,l_l y){
    return a[x.se]>a[y.se];
}
void cal(){
    vector<l_l>v;
    rep(i,1,n){
        a[i]=a[i]*10000+i;
    }
    
    rep(i,1,n){
        rep(j,i+1,n){
            if(a[i]>a[j])v.pb({i,j});
        }
    }
    SORT(v);
    vector<l_l>ans;
    ll vs=v.size();
    rep(i,0,vs-1){
        vector<l_l>k;
        k.pb(v[i]);
        while(i+1<=vs-1&&v[i].fi==v[i+1].fi){
            k.pb(v[i+1]);
            i++;
        }
        sort(k.begin(),k.end(),comp);
        for(auto x:k){
            ans.pb(x);
            swap(a[x.fi],a[x.se]);
        }
    }
    //rep(i,1,n)cout<<a[i]<<" ";cout<<endl;
    
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x.fi<<" "<<x.se<<endl;
    
}
int main(){fastio
    
    cin>>n;
    rep(i,1,n)cin>>a[i];
    cal();
    
    return 0;
}
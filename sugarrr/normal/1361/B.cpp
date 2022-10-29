
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
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
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
            cout<<x<<"/"<<y<<endl;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////


ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}

ll M=1e6+100;

bool anspro(){
    
    ll n,p;cin>>n>>p;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    if(p==1){
        if(n%2==1)cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    ll b=0,c=a[n-1];
    for(ll i=n-1;i>=0;i--){
        if(b==0){
            b=1;
            c=a[i];
            continue;
        }
        if(a[i]<c){
            while(b<=M){
                b=b*p;
                c--;
                if(a[i]==c)break;
            }
            if(b>M){
                ll ans=mod(mod(abs(b))*po(p,c));
                rep(j,0,i){
                    Add(ans,-po(p,a[j]));
                }
                cout<<mod(ans)<<endl;
                return 0;
            }
        }
        b--;
        if(b<0)b=abs(b);
    }
    cout<<mod(mod(abs(b))*po(p,c))<<endl;
    return 0;
}

int main(){fastio
    ll que;cin>>que;
    while(que--){
        anspro();
    }
    
    return 0;
}
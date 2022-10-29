#include <bits/stdc++.h>
//#include "bits/stdc++.h"
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
//
struct RSQ{
    ll n;
    vector<ll>data;
    RSQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
    }
    void update(ll k,ll a){
        k+=n-1;
        data[k]=a;
        while(k>0){
            k=(k-1)/2;
            data[k]=data[2*k+1]+data[2*k+2];
        }
    }
    void add(ll k,ll a){
        k+=n-1;
        data[k]+=a;
        while(k>0){
            k=(k-1)/2;
            data[k]=data[2*k+1]+data[2*k+2];
        }
    }
    ll query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)
};
//////////////////////////////////////////////////////

int main(){fastio
    ll n;cin>>n;
    vector<ll>x(n),v(n),compv(n);
    vector<l_l>idx(n);
    rep(i,0,n-1){cin>>x[i];idx[i]={x[i],i};}
    rep(i,0,n-1){cin>>v[i];compv[i]=v[i];}
    SORT(idx);
    SORT(compv);SORT(compv);
    rep(i,0,n-1)v[i]=POSL(compv,v[i]);
    ll ans=0;
    RSQ sm(n);
    RSQ kz(n);
    rep(j,0,n-1){
        ll i=idx[j].se;
        ll kaz=kz.query(0,v[i]+1);
        ll sum=sm.query(0,v[i]+1);
        ans+=kaz*x[i]-sum;
        kz.add(v[i],1);
        sm.add(v[i],x[i]);
        //cerr<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    
    return 0;
}
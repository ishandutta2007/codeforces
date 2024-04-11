//#include <bits/stdc++.h>
#include "bits/stdc++.h"
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
///////////////////////////
//
struct RBQRAQ{
    ll n;
    vector<ll>data,lazy;
    RBQRAQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
    }
    void eval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            data[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k];
                lazy[2*k+2]+=lazy[k];
            }
            lazy[k]=0;
        }
    }
    void add(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            lazy[k]+=x;
            eval(k,l,r);
        }else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            data[k]=max(data[2*k+1],data[2*k+2]);
        }
    }
    void add(ll a,ll b,ll x){add(a,b,x,0,0,n);}//[a,b)x
    ll query(ll a,ll b,ll k,ll l,ll r){
        eval(k,l,r);
        if(r<=a||b<=l)return -inf;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)
};
//////////////////////////////////////////////////////

struct mon{
    ll x,y,z;
};
bool comp(mon a,mon b){
    return a.x<b.x;
}

#define N 1000005
int main(){fastio
    ll n,m,p;cin>>n>>m>>p;
    ll va[N];rep(i,0,N-1)va[i]=inf;
    rep(i,1,n){
        ll a,b;cin>>a>>b;
        Min(va[a],b);
    }
    vector<l_l>a;
    ll prec=inf-1;
    for(ll i=N-1;i>=0;i--){
        if(prec>va[i]){
            a.pb({i,va[i]});
            prec=va[i];
        }
    }
    reverse(a.begin(),a.end());
    ll vb[N];rep(i,0,N-1)vb[i]=inf;
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        Min(vb[a],b);
    }
    vector<l_l>b;
    prec=inf-1;
    for(ll i=N-1;i>=0;i--){
        if(prec>vb[i]){
            b.pb({i,vb[i]});
            prec=vb[i];
        }
    }
    reverse(b.begin(),b.end());
    ll as=a.size();ll bs=b.size();
    RBQRAQ u(bs);
    rep(i,0,bs-1){
        u.add(i,i+1,-b[i].se);
    }
    ll ans=-inf;
    mon q[p];
    rep(i,0,p-1){
        cin>>q[i].x>>q[i].y>>q[i].z;
    }
    sort(q,q+p,comp);
    ll qpos=0;
    rep(i,0,as-1){
        while(qpos<=p-1){
            if(q[qpos].x<a[i].fi){
                ll bpos=upper_bound(b.begin(),b.end(),l_l(q[qpos].y,inf))-b.begin();
                u.add(bpos,bs,q[qpos].z);
                qpos++;
            }else{
                break;
            }
        }
        ll res=u.query(0,bs)-a[i].se;
        Max(ans,res);
    }
    cout<<ans<<endl;
    
    return 0;
}
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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

ll n,k;
vector<l_l>cal(vector<ll>&v){
    SORT(v);
    vector<l_l>res;
    rep(i,0,n-1){
        ll c=1;
        while(i+1<=n-1&&v[i]==v[i+1]){
            c++;i++;
        }
        res.pb({v[i],c});
    }
    return res;
}

int main(){fastio
    cin>>n>>k;
    vector<ll>A(n);
    rep(i,0,n-1)cin>>A[i];
    vector<l_l>a=cal(A);
    ll as=a.size();
    ll kaz[as],sum[as];
    rep(i,0,as-1){
        kaz[i]=a[i].se;
        sum[i]=a[i].se*a[i].fi;
        if(i!=0){
            kaz[i]+=kaz[i-1];
            sum[i]+=sum[i-1];
        }
    }
    //rep(i,0,as-1)cout<<kaz[i]<<" ";cout<<endl;
    //rep(i,0,as-1)cout<<sum[i]<<" ";cout<<endl;
    ll ans=inf;
    rep(i,0,as-1){
        ll kaz1=(i==0)?0:kaz[i-1];
        ll kaz2=n-kaz[i];
        ll pre1=(a[i].fi-1)*kaz1-(i==0?0:sum[i-1]);
        ll pre2=(sum[as-1]-sum[i])-(kaz2*(a[i].fi+1));
        ll res=k-a[i].se;
        if(res<=0){
            cout<<0<<endl;return 0;
        }
        if(res<=kaz1){
            Min(ans,pre1+res);
        }
        if(res<=kaz2){
            Min(ans,pre2+res);
        }
        if(res<=kaz1+kaz2){//True
            Min(ans,pre1+pre2+res);
        }
    }
    cout<<ans<<endl;
    return 0;
}
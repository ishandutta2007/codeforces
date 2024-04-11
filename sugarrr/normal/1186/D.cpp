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
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

ll N=10000000;

ll dow(dd a){
    ll k=(ll)((dd)N+a);
    k-=N;
    return k;
}
ll up(dd a){
    ll k=(ll)((dd)N+a+1.00-EPS);
    k-=N;
    return k;
}


int main(){fastio
    
    ll n;cin>>n;
    dd a[n];
    rep(i,0,n-1)cin>>a[i];
    ll b[n],c[n];
    rep(i,0,n-1){
        b[i]=dow(a[i]);
        c[i]=up(a[i]);
    }
    ll sum=0;
    rep(i,0,n-1){
        sum+=b[i];
    }
    /*rep(i,0,n-1){
        cout<<b[i]<<" "<<c[i]<<endl;
    }*/
    ll ans[n];
    rep(i,0,n-1){
        if(sum<0){
            ans[i]=c[i];
            sum+=(c[i]-b[i]);
        }else{
            ans[i]=b[i];
        }
    }
    rep(i,0,n-1){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
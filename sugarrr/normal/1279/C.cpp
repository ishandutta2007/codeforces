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
////////////////////////////

#define N 100005
bool ans(){
    ll n,m;cin>>n>>m;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll b[m];rep(i,0,m-1)cin>>b[i];
    ll c[N];memset(c,-1,sizeof(c));
    rep(i,0,m-1){
        c[b[i]]=i;
    }
    ll d[m];
    rep(i,0,n-1){
        if(c[a[i]]==-1)continue;
        d[c[a[i]]]=i;
    }
    //rep(i,0,m-1)cout<<d[i]<<" ";cout<<endl;
    ll ans=0;
    bool f[m];memset(f,false,sizeof(f));
    ll ma=-1;
    rep(i,0,m-1){
        if(ma>d[i])f[i]=true;
        Max(ma,d[i]);
    }
    rep(i,0,m-1){
        if(f[i]){
            ans++;
        }else{
            ans+=2*(d[i]-i)+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}

int main(){fastio
    ll q;cin>>q;
    while(q--){
        ans();
    }
    
    return 0;
}
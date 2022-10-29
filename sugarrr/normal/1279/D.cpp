#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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

#define N 1000005
int main(){fastio
    ll n;cin>>n;
    ll cou[N];memset(cou,0,sizeof(cou));
    vector<ll>v[n];
    ll vs[n];
    rep(i,0,n-1){
        ll k;cin>>k;
        vs[i]=k;
        while(k--){
            ll c;cin>>c;v[i].pb(c);
            cou[c]++;
        }
    }
    ll ans=0;
    rep(i,0,n-1){
        ll sum=0;
        for(auto x:v[i]){
            sum+=cou[x];
        }
        Add(ans,mod(sum)*bunbo(vs[i]));
    }
    
    ans=mod(ans*bunbo(mod(n*n)));
    cout<<mod(ans)<<endl;
    
    return 0;
}
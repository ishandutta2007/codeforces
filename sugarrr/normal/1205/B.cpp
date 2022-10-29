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


#define N 100005
//#define N 5
vector<ll>v[N];

ll ans=inf;
ll num[N];
bool used[N];
void dfs(ll k){
    used[k]=true;
    for(auto x:v[k]){
        if(num[x]!=-1&&num[k]+1-num[x]>=3){
            Min(ans,num[k]+1-num[x]);
            //cout<<num[k]+1-num[x]<<endl;
        }else if(num[k]+1-num[x]>=3){
            num[x]=num[k]+1;
            dfs(x);
        }
    }
    num[k]=-1;
}
int main(){fastio
    ll n;cin>>n;
    
    ll a[n];rep(i,0,n-1)cin>>a[i];
    memset(used,false,sizeof(used));
    rep(i,0,70){
        vector<ll>c;
        rep(j,0,n-1){
            if((a[j]>>i)&1)c.pb(j);
        }
        if(c.size()>=3){
            cout<<3<<endl;
            return 0;
        }
        if(c.size()==2){
            ll x=c[0],y=c[1];
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    /*
    rep(i,0,n-1){
        ll co;cin>>co;
        rep(j,0,co-1){
            ll x;cin>>x;
            v[i].pb(x);
        }
    }
    */
    rep(i,0,n-1){
        if(v[i].size()>=1){
            if(used[i])continue;
            memset(num,-1,sizeof(num));
            num[i]=1;
            dfs(i);
        }
    }
    
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
    
    return 0;
}
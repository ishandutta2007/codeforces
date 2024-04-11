#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_7 1000003
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
/*
vector<ll>v;
ll n,x;
ll maxn;
bool dfs(ll k){
    if(k==maxn){
        rep(i,0,maxn-1){
            rep(j,i,maxn-1){
                ll xo=0;
                rep(p,i,j)xo^=v[p];
                if(xo==0||xo==x)return 0;
            }
        }
        rep(i,0,maxn-1)cout<<v[i]<<" ";cout<<endl;
        return 0;
    }
    rep(i,1,(1<<n)-1){
        v.pb(i);
        dfs(k+1);
        v.pop_back();
    }
    return 0;
}
*/
int main(){fastio
    
    /*cin>>n>>x;
    cin>>maxn;
    dfs(0);
    cout<<"end"<<endl;*/
    
    ll n,x;cin>>n>>x;
    ll m;
    bool flag=true;
    if(x<(1<<n)){
        m=(1<<(n-1))-1;
        flag=false;
    }else{
        m=(1<<n)-1;
    }
    ll a[m+1];
    rep(i,1,m){
        ll k=1;
        while(1){
            if(i&k)break;
            else k*=2;
        }
        a[i]=k;
    }
    if(flag==false){
        ll y=1;
        while(1){
            if(y&x)break;
            else y*=2;
        }
        rep(i,1,m){
            if(a[i]>=y)a[i]*=2;
        }
    }
    cout<<m<<endl;
    rep(i,1,m){
        cout<<a[i]<<" ";
    }cout<<endl;
    
    return 0;
}
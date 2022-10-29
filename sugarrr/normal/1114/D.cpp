
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-8;
////////////////////////////////////////


int main(){
    ll m;cin>>m;
    ll q[m];rep(i,0,m-1)cin>>q[i];
    vector<ll>v;
    rep(i,0,m-1){
        if(i==0)v.pb(q[i]);
        else if(q[i-1]!=q[i])v.pb(q[i]);
    }
    //for(auto x:v)cout<<x<<" ";cout<<endl;
    vector<ll>u=v;
    reverse(u.begin(),u.end());
    ll n=v.size();
    ll dp[n+1][n+1];
    rep(i,0,n)dp[i][0]=dp[0][i]=0;
    rep(i,1,n){
        rep(j,1,n){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(v[i-1]==u[j-1])Max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    /*rep(i,0,n){
        rep(j,0,n){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    ll c=0;
    rep(i,1,n){
        rep(j,1,n){
            if(i+j>n)continue;
            Max(c,dp[i][j]);
        }
    }
    cout<<n-1-c<<endl;
    
    return 0;
}
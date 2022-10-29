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
#define fi first
#define se second
////////////////////////////

int main(){fastio
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll dp[n][n+1][2];rep(i,0,n-1)rep(j,0,n)rep(k,0,1)dp[i][j][k]=inf;
    if(a[0]==0){
        dp[0][1][0]=0;
        dp[0][0][1]=0;
    }else{
        if(a[0]%2==0){
            dp[0][1][0]=0;
        }else{
            dp[0][0][1]=0;
        }
    }
    rep(i,1,n-1){
        rep(j,0,n){
            if(a[i]==0){
                if(j+1<=n){
                    Min(dp[i][j+1][0],dp[i-1][j][0]);
                    Min(dp[i][j+1][0],dp[i-1][j][1]+1);
                }
                Min(dp[i][j][1],dp[i-1][j][0]+1);
                Min(dp[i][j][1],dp[i-1][j][1]);
            }else if(a[i]%2==0){
                if(j-1>=0){
                    Min(dp[i][j][0],dp[i-1][j-1][0]);
                    Min(dp[i][j][0],dp[i-1][j-1][1]+1);
                }
            }else{
                Min(dp[i][j][1],dp[i-1][j][0]+1);
                Min(dp[i][j][1],dp[i-1][j][1]);
            }
        }
    }
    /*
    rep(i,0,n-1){
        rep(j,0,n){
            rep(k,0,1){
                cout<<dp[i][j][k]<<" ";
            }cout<<endl;
        }cout<<endl;
    }cout<<endl;
    */
    ll ans=min(dp[n-1][n/2][0],dp[n-1][n/2][1]);
    cout<<ans<<endl;
    
    return 0;
}
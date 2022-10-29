#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
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
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    ll x=a[n-1];
    cout<<x<<" ";
    vector<ll>b;
    for(ll i=n-2;i>=0;i--){
        if(a[i]==a[i+1]||x%a[i]!=0){
            cout<<a[i]<<endl;return 0;
        }
    }
    
    return 0;
}




/*#define N 100000;

int main(){
    ll n,m,s;cin>>n>>m>>s;
    n=n*n;
    ll dp[n+1][s+1];memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    rep(i,1,n){
        ll res=n+1-i;
        rep(j,0,s){
            for(ll k=1;;k++){
                if(j-k*res<0)break;
                dp[i][j]=(dp[i][j]+dp[i-1][j-k*res])%N;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,s){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    ll ans=0;
    rep(j,0,s){
        ans=(ans+dp[n][j])%N;
    }
    cout<<ans<<endl;
    
    
    return 0;
}*/
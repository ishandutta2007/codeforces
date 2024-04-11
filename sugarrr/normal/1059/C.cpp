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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
const double EPS=1E-8;
////////////////////////////////////////

vector<int>ans;

int po[26];

void dfs(int m,int k){
    if(m<=3){
        if(m==1)ans.pb(po[k]);
        else if(m==2){ans.pb(po[k]);ans.pb(po[k]*2);}
        else if(m==3){ans.pb(po[k]);ans.pb(po[k]);ans.pb(po[k]*3);}
        return;
    }
    int u=(m+1)/2;
    rep(i,1,u)ans.pb(po[k]);
    dfs(m-u,k+1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    int n;cin>>n;
    po[0]=1;
    rep(i,0,24)po[i+1]=2*po[i];
    dfs(n,0);
    for(auto x:ans)cout<<x<<" ";
    
    return 0;
}
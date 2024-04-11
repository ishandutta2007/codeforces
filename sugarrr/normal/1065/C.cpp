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
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
//const long double EPS=1E-8;
////////////////////////////////////////



int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n,k;cin>>n>>k;
    ll h[n];
    rep(i,0,n-1)cin>>h[i];
    sort(h,h+n);
    
    if(h[0]==h[n-1]){
        cout<<0<<endl;
        return 0;
    }
    int N=200001;
    ll x[N];
    int pos=n-1;
    rep(i,0,N-1){
        ll y=N-i-1;
        while(pos>=0&&y<=h[pos]){
            pos--;
        }
        x[i]=(n-1)-pos;
    }
   // rep(i,0,N-1)cout<<x[i]<<" ";cout<<endl;
    ll sum=0;
    ll ans=0;
    pos=0;
    while(pos<=N-1&&x[pos]!=n){
        while(sum+x[pos]<=k){
            if(x[pos]==n||pos>=N)break;
            sum+=x[pos];
            pos++;
        }
        ans++;
        sum=0;
    }
    cout<<ans<<endl;
    
    
    return 0;
}
//ios::sync_with_stdio(false);cin.tie(0);
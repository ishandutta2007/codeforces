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
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

int main(){
    ll n,k;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll s[k];memset(s,0,sizeof(s));
    rep(i,0,k-1){
        rep(j,0,n-1){
            if((j-i)%k==0)continue;
            else s[i]+=a[j];
        }
        
    }
    ll ans=0;
    /*rep(i,0,k-1){
        cout<<s[i]<<" ";
    }cout<<endl;*/
    rep(i,0,k-1){
        ans=max(ans,abs(s[i]));
    }
    cout<<ans<<endl;
    
    return 0;
}
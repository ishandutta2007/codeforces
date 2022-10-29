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
    
    ll n,m;cin>>n>>m;
    ll ans1=max(0,n-2*m);
    ll k=1;
    ll ans2;
    if(m==0){
        ans2=n;
    }else{
        while(1){
            if(k*(k-1)/2>=m)break;
            k++;
        }
        ans2=n-k;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
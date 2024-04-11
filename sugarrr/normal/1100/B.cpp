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
    ll n,m;cin>>n>>m;
    ll a[m];
    rep(i,0,m-1){
        cin>>a[i];
        a[i]--;
    }
    ll c[n];memset(c,0,sizeof(c));
    bool ans[m];memset(ans,false,sizeof(ans));
    ll d=0;
    rep(i,0,m-1){
        if(c[a[i]]==0){
            c[a[i]]++;
            d++;
            if(d==n){
                d=0;
                rep(j,0,n-1){
                    c[j]--;
                    if(c[j]>=1)d++;
                }
                ans[i]=true;
            }
        }else{
            c[a[i]]++;
        }
    }
    rep(i,0,m-1){
        if(ans[i])cout<<1;
        else cout<<0;
    }cout<<endl;
    return 0;
}
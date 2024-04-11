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
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    rep(i,0,(1<<n)-1){
        ll sum=0;
        rep(j,0,n-1){
            if((i>>j)&1){
                sum+=a[j];
            }else{
                sum-=a[j];
            }
        }
        sum=abs(sum);
        if(sum%360==0){
            cout<<"YES"<<endl;
            return 0;
        }
        //cout<<sum<<endl;
    }
    cout<<"NO"<<endl;
    return 0;
}
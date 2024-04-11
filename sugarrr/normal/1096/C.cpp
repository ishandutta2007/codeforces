
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
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
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

int main(){
    ll t;cin>>t;
    ll ans[200];rep(i,0,179)ans[i]=-1;
    rep(i,1,179){
        bool flag=true;
        rep(n,3,360){
            rep(k,1,(n-2)){
                if(180*k==i*n){
                    if(ans[i]==-1)ans[i]=n;
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
    }
    /*rep(i,1,179){
        cout<<i<<" "<<ans[i]<<endl;
    }*/
    while(t--){
        ll ang;cin>>ang;
        cout<<ans[ang]<<endl;
    }
    return 0;
}
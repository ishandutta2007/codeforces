
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
    l_l a[3];
    rep(i,0,2){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+3);
    if(a[0].first==a[2].first){
        ll ans=a[2].second-a[0].second+1;
        cout<<ans<<endl;
        rep(i,a[0].second,a[2].second){
            cout<<a[0].first<<" "<<i<<endl;
        }
    }else{
        vector<l_l>ans;
        rep(i,a[0].first,a[1].first-1){
            ans.pb(l_l(i,a[0].second));
        }
        rep(i,a[1].first+1,a[2].first){
            ans.pb(l_l(i,a[2].second));
        }
        ll c[3];rep(i,0,2)c[i]=a[i].second;
        sort(c,c+3);
        rep(i,c[0],c[2]){
            ans.pb(l_l(a[1].first,i));
        }
        cout<<ans.size()<<endl;
        for(auto x:ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    
    return 0;
}
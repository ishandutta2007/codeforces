#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
using namespace std;
typedef long long ll;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
//#define i_5 (ll)(1E9+5)
#define i_5 998244351
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
    ll n;cin>>n;
    l_l x[n];rep(i,0,n-1)cin>>x[i].first>>x[i].second;
    l_l a[n];rep(i,0,n-1)cin>>a[i].first>>a[i].second;
    /*if(n==1){
        cout<<x[0].first+a[0].first<<" "<<x[0].second+a[0].second;
        return 0;
    }*/
    sort(x,x+n);
    sort(a,a+n);
    cout<<x[0].first+a[n-1].first<<" "<<x[0].second+a[n-1].second<<endl;
    
    
    return 0;
}
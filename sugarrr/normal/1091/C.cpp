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

vector<ll> prime(ll n){
    vector<ll>res;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==n)res.pb(i);
            else{
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    
    return res;
}


int main(){
    ll n;cin>>n;
    vector<ll>pp=prime(n);
    //for(auto x:p)cout<<x<<" ";
    vector<ll>ans;
    for(auto p:pp){
        ll t=n/p-1;
        ll c=t+1+p*t*(t+1)/2;
        ans.pb(c);
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    
    
    return 0;
}
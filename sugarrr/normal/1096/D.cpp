
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
    ll n;cin>>n;
    string s;cin>>s;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    
    ll dp[n][4];memset(dp,0,sizeof(dp));
    string t="hard";
    if(s[0]==t[0])dp[0][0]=a[0];
    rep(i,1,n-1){
        rep(j,0,3){
            if(s[i]!=t[j])dp[i][j]=dp[i-1][j];
            else{
                if(j-1>=0)dp[i][j]=min(dp[i-1][j]+a[i],dp[i-1][j-1]);
                else dp[i][j]=dp[i-1][j]+a[i];
            }
        }
    }
    /*rep(i,0,n-1){
        rep(j,0,3){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n-1][3]<<endl;
    
    return 0;
}
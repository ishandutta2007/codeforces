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
    
    int t;cin>>t;
    while(t--){
        ll n,x,y,d;cin>>n>>x>>y>>d;
        
        vector<ll>ans;
        if(abs((y-x))%d==0)ans.pb(abs(y-x)/d);
        if((y-1)%d==0){
            ll k=(x-1)/d;
            if((x-1)%d!=0)k++;
            k+=(y-1)/d;
            ans.pb(k);
        }
        if((n-y)%d==0){
            ll k=(n-x)/d;
            if((n-x)%d!=0)k++;
            k+=(n-y)/d;
            ans.pb(k);
        }
        if(ans.size()==0)cout<<-1<<endl;
        else{
            sort(ans.begin(),ans.end());
            cout<<ans[0]<<endl;
        }
        
    }
    
    return 0;
}
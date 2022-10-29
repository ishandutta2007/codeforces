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
    int n;cin>>n;
    string s;cin>>s;
    vector<int>a;
    
   if(n<=4){
        int ans=0;
        rep(i,0,n-1)if(s[i]=='G')ans++;
        cout<<ans<<endl;
        return 0;
    }
    
    if(s[0]=='S')a.pb(0);
    int pos=0;
    while(pos<=n-1){
        int c=1;
        while(pos<=n-2&&s[pos]==s[pos+1]){
            pos++;
            c++;
        }
        a.pb(c);
        pos++;
    }
    
    int m=a.size();
    int sum=0;
    for(int i=0;i<=m-1;i+=2)sum+=a[i];
    int ma=0;
    for(int i=0;i<=m-1;i+=2){
        ma=max(ma,a[i]+1);
        if(i+2<=m-1&&a[i+1]==1)ma=max(ma,a[i]+a[i+2]+1);
    }
    
    cout<<min(sum,ma)<<endl;
    
    
    
    return 0;
}
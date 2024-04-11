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

#define MAX_N (ll)2E6///
vector<int>prime;
bool is_prime[MAX_N+1];
void precal(){
    rep(i,0,MAX_N)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,MAX_N){
        if(is_prime[i]){
            prime.pb(i);
            for(int j=2*i;j<=MAX_N;j+=i)is_prime[j]=false;
        }
    }
}
vector<i_i> fact(ll n){//2<=n<=MAX_N^2
    vector<i_i>v;
    for(int p:prime){
        if(p*p>n)break;
        int c=0;
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)v.pb(i_i(p,c));//pc
    }
    if(n!=1){
        int vsize=v.size();
        if(vsize>=1&&v[vsize-1].first==n)v[vsize-1].second++;
        else v.pb(i_i(n,1));
    }
    return v;
}
/////////////////////////////////////////////////////

int main(){
    //precal();
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    
    ll dp[n+100];memset(dp,0,sizeof(dp));
    dp[0]=1;
    rep(i,0,n-1){
        vector<int>v;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                v.pb(j);
                if(a[i]!=j*j)v.pb(a[i]/j);
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        for(auto x:v){
            if(x<=n)dp[x]=mod(dp[x]+dp[x-1]);
        }
        //rep(i,0,n)cout<<dp[i]<<" ";cout<<endl;
    }
    ll ans=0;
    rep(i,1,n)ans=mod(ans+dp[i]);
    cout<<mod(ans)<<endl;
    
    return 0;
}
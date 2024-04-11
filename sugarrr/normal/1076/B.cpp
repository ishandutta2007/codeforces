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
//ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////
#define MAX_N (ll)2E7///
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
    
    
    ll n;cin>>n;
    if(n%2==0){
        cout<<n/2<<endl;
    }else{
        int m=(int)sqrt(n);
        rep(i,2,m){
            if(n%i==0){
                n-=i;
                cout<<1+n/2<<endl;
                return 0;
            }
        }
        cout<<1<<endl;
    }
    
    return 0;
}
//ios::sync_with_stdio(false);cin.tie(0);
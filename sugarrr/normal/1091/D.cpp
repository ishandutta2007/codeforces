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
#define N 1000004

ll kai[N];
ll kai2[N];
ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return mod(po(mod(mod(i)*mod(i)),p/2));
    else  return mod(mod(i)*mod(po(i,p-1)));
}
void calc(){
    kai[0]=1;
    kai2[0]=1;
    for(int i=1;i<N;i++){
        kai[i]=mod(kai[i-1]*i);
    }
}
ll comb(ll n,ll k){
    if(n==0){
        if(k==0)return 1;
        else return 0;
    }
    else if(n<k)return 0;
    else return mod(mod(mod(kai[n])*mod(kai2[n-k]))*mod(kai2[k]));
}

int main(){
    calc();
    ll n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    ll g[n+1];
    g[2]=0;
    rep(i,2,n-1){
        g[i+1]=mod(mod(g[i]+kai[i]-1)*(i+1));
    }
    ll ans=mod(g[n]+kai[n]);
    cout<<ans<<endl;
    
    /*rep(i,2,5){
        cout<<g[i]<<endl;
    }*/
    
    
    return 0;
}

/*int main(){
    ll n;cin>>n;
    vector<ll>b;
    ll a[n];rep(i,0,n-1)a[i]=i+1;
    do{
        rep(i,0,n-1)b.pb(a[i]);
    }while(next_permutation(a,a+n));
    
    ll s=b.size();
    ll ans=0;
    rep(i,0,s-n){
        ll sum=0;
        rep(j,0,n-1){
            sum+=b[i+j];
        }
        if(sum==n*(n+1)/2)ans++;
    }
    cout<<ans<<endl;
    
    
    return 0;
}*/
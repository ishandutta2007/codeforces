
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////
#define MAX_N (ll)2E6///
vector<ll>prime;
bool is_prime[MAX_N+1];
void precal(){
    rep(i,0,MAX_N)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,MAX_N){
        if(is_prime[i]){
            prime.pb(i);
            for(ll j=2*i;j<=MAX_N;j+=i)is_prime[j]=false;
        }
    }
}
vector<l_l> fact(ll n){//2<=n<=MAX_N^2
    vector<l_l>v;
    for(ll p:prime){
        if(p*p>n)break;
        ll c=0;
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)v.pb(l_l(p,c));//pc
    }
    if(n!=1){
        ll vsize=v.size();
        if(vsize>=1&&v[vsize-1].first==n)v[vsize-1].second++;
        else v.pb(l_l(n,1));
    }
    return v;
}
/////////////////////////////////////////////////////


ll many(ll n,ll x){
    ll res=0;
    while(n>=x){
        res+=n/x;
        n/=x;
    }
    return res;
}

int main(){
    precal();
    ll n,b;cin>>n>>b;
    vector<l_l>v=fact(b);
    ll s=v.size();
    ll a[s];memset(a,0,sizeof(a));
    rep(i,0,s-1){
        ll pri=v[i].first;
        a[i]=many(n,pri);
    }
    /*rep(i,0,s-1){
        cout<<a[i]<<" ";
    }cout<<endl;*/
    ll ans=a[0]/v[0].second;
    rep(i,1,s-1){
        ll com=a[i]/v[i].second;
        Min(ans,com);
    }
    cout<<ans<<endl;
    return 0;
}
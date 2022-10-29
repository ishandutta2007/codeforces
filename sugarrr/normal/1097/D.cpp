#include <bits/stdc++.h>
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
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////
ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return mod(po(mod(mod(i)*mod(i)),p/2));
    else  return mod(mod(i)*mod(po(i,p-1)));
}
/////////////////////////////////
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat a,mat b){/*ab*/
    mat c(a.size(),vec(b[0].size()));
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<b[0].size();j++){
            for(ll k=0;k<a[0].size();k++){
                c[i][j]=mod(c[i][j]+mod(a[i][k]*b[k][j]));
            }
        }
    }
    return c;
}
mat pow(mat a,ll n){/*an*/
    mat b(a.size(),vec(a.size()));
    for(ll i=0;i<a.size();i++){
        b[i][i]=1;
    }
    while(n>0){
        if(n&1)b=mul(b,a);
        a=mul(a,a);
        n>>=1;
    }
    return b;
}
//////////////////////////////////////////
#define MAX_N 35000000///
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
ll k;
ll bunbo(ll m){
    return po(m,i_5);
}

ll ans=1;

void calc(l_l x){
    ll prim=x.first;
    ll ss=x.second+1;
    ll vv[ss];
    vv[0]=1;rep(i,1,ss-1)vv[i]=mod(prim*vv[i-1]);
    mat p(ss,vec(ss));
    rep(i,0,ss-1){
        rep(j,0,ss-1){
            p[i][j]=0;
        }
    }
    rep(j,0,ss-1){
        ll xxx=bunbo(j+1);
        rep(i,0,j){
            p[i][j]=xxx;
        }
    }
    p=pow(p,k);
    mat q(ss,vec(1));
    
    rep(i,0,ss-2)q[i][0]=0;
    q[ss-1][0]=1;
    q=mul(p,q);
    ll sum=0;
    rep(i,0,ss-1){
        Add(&sum,mod(q[i][0]*vv[i]));
    }
    ans=mod(ans*sum);
}

int main(){
    precal();
    ll n;
    cin>>n>>k;
    vector<l_l> q=fact(n);
    for(auto x:q){
        calc(x);
    }
    cout<<ans<<endl;
   
    return 0;
}
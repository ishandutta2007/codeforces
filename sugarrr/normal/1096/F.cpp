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


ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return mod(po(mod(mod(i)*mod(i)),p/2));
    else  return mod(mod(i)*mod(po(i,p-1)));
}
ll f(ll n){
    return po(n,i_5);
}
#define N 200005
ll kai[N];
ll kai2[N];
void calc(){
    kai[0]=1;
    kai2[0]=1;
    for(int i=1;i<N;i++){
        kai[i]=mod(kai[i-1]*i);
        kai2[i]=mod(po(kai[i],i_5));
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
/////////////////////////////////
//[1,n]
#define max_n 400000//
ll bit[max_n+1],n;
ll sum(ll i){//a[1]~a[i]
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x){//a[i]x
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
////////////////////////////////////////

int main(){
    calc();
    cin>>n;
    ll p[n+1];rep(i,1,n)cin>>p[i];
    ll count=0;
    rep(i,1,n){
        if(p[i]==-1)continue;
        count+=sum(n)-sum(p[i]-1);
        add(p[i],1);
    }
    //cout<<count<<endl;
    
    ll mc[n+1];rep(i,1,n)mc[i]=1;mc[0]=0;
    rep(i,1,n){
        if(p[i]!=-1){
            mc[p[i]]=0;
        }
    }
    
    rep(i,2,n)mc[i]+=mc[i-1];
    //rep(i,1,n)cout<<mc[i]<<" ";return 0;
    ll q=mc[n];
    ll count2=0;
    ll c=0;
    rep(i,1,n){
        if(p[i]!=-1){
            ll add=mod(c*mod((q-mc[p[i]-1])));
            ll add2=mod(mod((q-c))*mc[p[i]-1]);
            Add(&count2,add);
            Add(&count2,add2);
        }else{
            c++;
        }
    }
    count2=mod(mod(mod(count2*kai[q-1]))*f(kai[q]));
    count=mod(mod(mod(count*kai[q]))*f(kai[q]));
    
    ll count3=mod(kai[q]*comb(q,2));
    count3=mod(count3*f(2));
    count3=mod(count3*f(kai[q]));
    
    //cout<<count<<" "<<count2<<" "<<count3<<endl;
    // cout<<q<<endl;
    
    ll ans=mod(count+count2+count3);
    
    cout<<ans<<endl;
    
    return 0;
}
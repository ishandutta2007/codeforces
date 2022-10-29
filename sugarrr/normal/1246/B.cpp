//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 1024(TLE)
*/
 
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            //cout<<x<<"/"<<y;
            cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////




#define MAX_N (ll)2E5///
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

vector<l_l> fact(ll n){
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


#define N 100005
ll limit[N];

void prepre(){
    rep(i,2,N-1){
        ll cnt=0,res=i;
        while(res<N){
            res*=i;
            cnt++;
        }
        limit[i]=cnt;
    }
}

ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        if(p==1)return i;
        if(p%2==0)return po(i*i,p/2);
        return (i*po(i,p-1));
    }
}

ll k;
vector<l_l>henkan(vector<l_l>z){
    vector<l_l>v;
    for(auto x:z){
        if(x.se%k==0)continue;
        v.pb({x.fi,x.se%k});
    }
    return v;
}
l_l cal(ll n){
    vector<l_l>z=fact(n);
    vector<l_l>v=henkan(z);
    if(v.size()==0){
        return {1,1};
    }
    l_l no={-1,-1};
    ll my=1,op=1;
    for(auto x:v){
        if(k-x.se>limit[x.fi])return no;
        my*=po(x.fi,x.se);
        op*=po(x.fi,k-x.se);
        if(my>N||op>N)return no;
    }
    return {my,op};
}


int main(){fastio
    precal();
    prepre();
    //rep(i,2,11)cout<<i<<" "<<limit[i]<<endl;
    ll n;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    vector<l_l>v;
    ll cnt=0;
    rep(i,0,n-1){
        
        l_l t=cal(a[i]);
        if(t==l_l{1,1})cnt++;
        else if(t==l_l{-1,-1})continue;
        else{
            v.pb(t);
        }
    }
    SORT(v);
    ll ans=cnt*(cnt-1)/2;
    ll vs=v.size();
    rep(i,0,vs-1){
        l_l op={v[i].se,v[i].fi};
        ans+=upper_bound(v.begin()+i+1,v.end(),op)-lower_bound(v.begin()+i+1,v.end(),op);
    }
    cout<<ans<<endl;
    
    return 0;
}
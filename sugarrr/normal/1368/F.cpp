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
//#define endl "\n"  //
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


template<typename T, typename Func_mv>
struct Segtree {
    ll n, n_org;
    vector<T> dat;
    Func_mv merge_values;  //datadata
    T te; //data
 
    Segtree(){}
    Segtree(ll n_org,
                Func_mv merge_values,
                T te):
                n_org(n_org),
                merge_values(merge_values),
                te(te){
        n = 1;
        while(n < n_org) n <<= 1;
        dat.resize(2*n-1, te);
    }
 
    void build(vector<T>& A){
        for(ll k=0; k<ll(A.size()); k++) dat[k+n-1] = A[k];
        for(ll k=n-2; k>=0; k--) dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
    }
    void update(ll k, T x){ //k
        k+=n-1;
        dat[k]=x;
        while(k>0){
            k=(k-1)/2;
            dat[k]=merge_values(dat[2*k+1],dat[2*k+2]);
        }
    }
    void add(ll k,T x){//k
        k+=n-1;
        dat[k]+=x;
        while(k>0){
            k=(k-1)/2;
            dat[k]=merge_values(dat[2*k+1],dat[2*k+2]);
        }
    }
    T get(ll a, ll b){ //[a,b]()get
        return query(a, b+1, 0, 0, n);
    }
    
private:
    T query(ll a, ll b, ll k, ll lb, ll rb){
        if(rb<=a || b<=lb) return te;
        if(a<=lb && rb<=b) return dat[k];
        ll mb = (lb+rb)>>1;
        T vl = query(a, b, 2*k+1, lb, mb);
        T vr = query(a, b, 2*k+2, mb, rb);
        return merge_values(vl, vr);
    }
};
auto make_segtree = [](ll N){ //auto make_segtree = [&](ll N)
    
    using T=ll;
    auto merge_values=[](T&a,T&b){return max(a,b);};
    T te=-inf;
    
    return Segtree<T, decltype(merge_values)>
        (N, merge_values, te);
};


void end(){
    cout<<0<<endl;
    fflush(stdout);
    exit(0);
}


#define N 1005
ll n;
ll last[N];
ll s[N];
ll endcount=0;

ll nxt;
void erase(ll t,ll sz){
    rep(i,0,sz-1){
        ll pos=t+i;
        while(pos>n)pos-=n;
        if(s[pos]==1)endcount--;
        s[pos]=0;
    }
}
void out(vector<ll>t){
    cout<<t.size()<<" ";
    for(auto x:t){
        cout<<x<<" ";
        s[x]=1;
        endcount++;
    }
    cout<<endl;
    fflush(stdout);
    ll ts=t.size();
    ll z;cin>>z;
    erase(z,ts);
}

int main(){fastio
    cin>>n;
    if(n<=3){
        end();
    }
    
    ll mx=0;
    vector<ll>v;
    rep(mxv,2,n){
        auto ep = make_segtree(n-mxv+1);
        vector<ll> init(n-mxv+1);
        ep.build(init);
        rep(i,1,n-mxv){
            ll valll=ep.get(max(0,i-mxv),i-1)-1;
            ep.update(i,valll);
        }
        
        if(chmax(mx,ep.get(n-mxv,n-mxv)+n-mxv)){
            v.clear();
            ll dp[n-mxv+1];
            rep(i,0,n-mxv){
                dp[i]=ep.get(i,i)+i;
            }
            ll pos=n-mxv;
            while(pos>0){
                rrep(i,pos-1,0){
                    if(dp[pos]==dp[i]+(pos-i-1)){
                        v.pb(pos-i);
                        pos=i;
                        break;
                    }
                }
            }
            v.pb(mxv);
        }
    }
   // for(auto x:v)cout<<x<<" ";cout<<endl;
    ll cnt=0;
    rep(i,1,n)last[i]=1;
    rep(i,0,v.size()-1){
        cnt+=v[i];
        last[cnt]=0;
    }
   // rep(i,1,n)cout<<last[i]<<" ";cout<<endl;
    
    rep(zzz,1,2000){
        vector<ll>res;
        rep(i,1,n){
            if(last[i]==1&&s[i]==0)res.pb(i);
        }
        out(res);
        if(endcount==0)break;
        endcount=0;
    }
    end();
    
    return 0;
}
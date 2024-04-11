
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
dd EPS=1E-12;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"  //
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
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;
//////////////////////////

ll N;
//from betrue12 Codeforces 1326E
template<typename F, typename T, typename Func_mf, typename Func_op, typename Func_mv>
struct LazySegtree {
    ll n, n_org;
    vector<T> dat;
    vector<F> laz;
    Func_mf merge_functions; //lazylazy
    Func_op operate;       //datalazy
    Func_mv merge_values;  //datadata
    F fe; //lazy
    T te; //data
 
    LazySegtree(){}
    LazySegtree(ll n_org,
                Func_mf merge_functions,
                Func_op operate,
                Func_mv merge_values,
                F fe, T te):
                n_org(n_org),
                merge_functions(merge_functions),
                operate(operate),
                merge_values(merge_values),
                fe(fe), te(te){
        n = 1;
        while(n < n_org) n <<= 1;
        dat.resize(2*n-1, te);
        laz.resize(2*n-1, fe);
    }
 
    void build(vector<T>& A){
        for(ll k=0; k<ll(A.size()); k++) dat[k+n-1] = A[k];
        for(ll k=n-2; k>=0; k--) dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
    }
    void update(ll a, ll b, F x){ //[a,b]update
        update(a, b+1, x, 0, 0, n);
    }
    T get(ll a, ll b){ //[a,b]()get
        return query(a, b+1, 0, 0, n);
    }
    T bin(ll x){
        ll ok=-1,ng=N;
        while(abs(ok-ng)>1){
            ll mid=(ok+ng)/2;
            if(get(mid,mid)>=x){
                ok=mid;
            }else{
                ng=mid;
            }
        }
        return ok;
    }
 
    
private:
    void eval(ll k, ll w){
        if(laz[k] == fe) return;
        operate(dat[k], laz[k], w);
        if(k < n-1){
            merge_functions(laz[2*k+1], laz[k]);
            merge_functions(laz[2*k+2], laz[k]);
        }
        laz[k] = fe;
    }
    T query(ll a, ll b, ll k, ll lb, ll rb){
        eval(k, rb-lb);
        if(rb<=a || b<=lb) return te;
        if(a<=lb && rb<=b) return dat[k];
        ll mb = (lb+rb)>>1;
        T vl = query(a, b, 2*k+1, lb, mb);
        T vr = query(a, b, 2*k+2, mb, rb);
        return merge_values(vl, vr);
    }
    void update(ll a, ll b, F x, ll k, ll lb, ll rb){
        eval(k, rb-lb);
        if(b <= lb || rb <= a) return;
        if(a <= lb && rb <= b){
            merge_functions(laz[k], x);
            eval(k, rb-lb);
        }else{
            ll mb = (lb+rb)>>1;
            update(a, b, x, 2*k+1, lb, mb);
            update(a, b, x, 2*k+2, mb, rb);
            dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
        }
    }
};
auto make_segtree = [](ll N){ //auto make_segtree = [&](ll N)
    //
    using F = ll;
    using T = ll;
    auto merge_functions = [](F& f, F& g){f += g;};
    auto operate = [](T& v, F& f, ll w){v += f*w;};
    auto merge_values = [](T& a, T& b){return a+b;};
    F fe = 0;
    T te = 0;
    
    return LazySegtree<F, T, decltype(merge_functions), decltype(operate), decltype(merge_values)>
        (N, merge_functions, operate, merge_values, fe, te);
};
/*
auto st = make_segtree(n);
vector<ll> init(n);
st.build(init);
 */
/*(init)infinf/2
Tinf
https://atcoder.jp/contests/arc073/submissions/14194347 (WA) inf
https://atcoder.jp/contests/arc073/submissions/14194333 (AC) inf/2
*/

typedef pair<l_l,ll> pll;

int main(){fastio
    
    ll n,q;cin>>n>>q;
    N=n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    vector<pll>que;
    rep(i,0,q-1){
        ll x,y;cin>>x>>y;
        que.pb({{n-1-y,x},i});
    }
    SORT(que);
    ll ans[q];memset(ans,-1,sizeof(ans));
    ll qpos=0;
    auto st = make_segtree(n);
    vector<ll> init(n);
    st.build(init);
    rep(i,0,n-1){
        
        if(a[i]<=i+1){
            ll ret=(i+1)-a[i];
            ll pos=st.bin(ret);
            chmin(pos,i);
            if(pos>=0){
                st.update(0,pos,1);
            }
        }
      //  rep(j,0,n-1)cout<<st.get(j,j)<<" ";cout<<endl;
        while(qpos<=q-1){
            if(que[qpos].fi.fi==i){
                ll x=que[qpos].fi.se;
                ans[que[qpos].se]=st.get(x,x);
                qpos++;
            }else{
                break;
            }
        }
    }
    rep(i,0,q-1)cout<<ans[i]<<endl;
    return 0;
}
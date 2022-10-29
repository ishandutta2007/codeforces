#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////


//from betrue12 Codeforces 1326E
template<typename F, typename T, typename Func_mf, typename Func_op, typename Func_mv>
struct LazySegtree {
    int n, n_org;
    vector<T> dat;
    vector<F> laz;
    Func_mf merge_functions; //lazylazy
    Func_op operate;       //datalazy
    Func_mv merge_values;  //datadata
    F fe; //lazy
    T te; //data
 
    LazySegtree(){}
    LazySegtree(int n_org,
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
        for(int k=0; k<int(A.size()); k++) dat[k+n-1] = A[k];
        for(int k=n-2; k>=0; k--) dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
    }
 
    void eval(int k, int w){
        if(laz[k] == fe) return;
        operate(dat[k], laz[k], w);
        if(k < n-1){
            merge_functions(laz[2*k+1], laz[k]);
            merge_functions(laz[2*k+2], laz[k]);
        }
        laz[k] = fe;
    }
 
    void update(int a, int b, F x){
        update(a, b+1, x, 0, 0, n);
    }
 
    void update(int a, int b, F x, int k, int lb, int rb){
        eval(k, rb-lb);
        if(b <= lb || rb <= a) return;
        if(a <= lb && rb <= b){
            merge_functions(laz[k], x);
            eval(k, rb-lb);
        }else{
            int mb = (lb+rb)>>1;
            update(a, b, x, 2*k+1, lb, mb);
            update(a, b, x, 2*k+2, mb, rb);
            dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
        }
    }
 
    T get(int a, int b){
        return query(a, b+1, 0, 0, n);
    }
 
    T query(int a, int b, int k, int lb, int rb){
        eval(k, rb-lb);
        if(rb<=a || b<=lb) return te;
        if(a<=lb && rb<=b) return dat[k];
        int mb = (lb+rb)>>1;
        T vl = query(a, b, 2*k+1, lb, mb);
        T vr = query(a, b, 2*k+2, mb, rb);
        return merge_values(vl, vr);
    }
};

auto make_segtree = [](int N){ //auto make_segtree = [&](int N)
    
    //
    
    using F = ll;
    using T = ll;
    auto merge_functions = [](F& f, F& g){f += g;};
    auto operate = [](T& v, F& f, ll w){v += f;};
    auto merge_values = [](T& a, T& b){return min(a, b);};
    F fe = 0;
    T te = inf;
    
    
    
    
    
    return LazySegtree<F, T, decltype(merge_functions), decltype(operate), decltype(merge_values)>
        (N, merge_functions, operate, merge_values, fe, te);
};
/*
auto st = make_segtree(2*N+1);
vector<ll> init(2*N+1);
st.build(init);
 */

int main(){fastio
    int N;
    cin >> N;
    vector<int> P(N), Q(N), pos(N+1);
    for(int i=0; i<N; i++){
        cin>>P[i];
        pos[P[i]] = i;
    }
    for(int i=0; i<N; i++){
        cin>>Q[i];
        Q[i]--;
    }
    
    auto st = make_segtree(2*N+1);
    vector<ll> init(2*N+1);
    st.build(init);
 
    int now = N;
    st.update(2*pos[N]+1, 2*N, 1);
    for(int i=0; i<N; i++){
        cout<<now<<" ";
        st.update(2*Q[i]+2, 2*N, -1);
        while(now > 0 && st.get(0, 2*N) == st.get(2*N, 2*N)){
            now--;
            st.update(2*pos[now]+1, 2*N, 1);
        }
    }
    return 0;
}
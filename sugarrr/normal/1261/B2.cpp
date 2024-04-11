//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

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
    //
    /*
    using T = ll;
    auto merge_values = [](T& a, T& b){return min(a, b);};
    T te = inf;
    */
    //
    /*
    using T=ll;
    auto merge_values=[](T&a,T&b){return max(a,b);};
    T te=-inf;*/
    
    //
    
    using T=ll;
    auto merge_values=[](T&a,T&b){return a+b;};
    T te=0;
    
    return Segtree<T, decltype(merge_values)>
        (N, merge_values, te);
};
/*
auto st = make_segtree(n);
vector<ll> init(n);
st.build(init);
 */

bool comp(l_l a,l_l b){
    if(a.fi==b.fi)return a.se<b.se;
    return a.fi>b.fi;
}

struct que{
    ll k,pos,id;
};
bool co1(que a,que b){
    return a.k<b.k;
}

int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    l_l b[n];rep(i,0,n-1)b[i]={a[i],i};
    sort(b,b+n,comp);
    
    auto st = make_segtree(n);
    vector<ll> init(n);st.build(init);
    
    ll q;cin>>q;
    vector<que>Q(q);
    rep(i,0,q-1){
        cin>>Q[i].k>>Q[i].pos;
        Q[i].k--;
        Q[i].id=i;
    }
    sort(Q.begin(),Q.end(),co1);
    ll ans[q];memset(ans,-1,sizeof(ans));
    rep(i,0,q-1){
        if(i==0){
            rep(j,0,Q[0].k){
                st.update(b[j].se,1);
            }
        }else if(Q[i-1].k<Q[i].k){
            rep(j,Q[i-1].k+1,Q[i].k){
                st.update(b[j].se,1);
            }
        }
        ll ok=n-1,ng=-1;
        while(abs(ok-ng)>1){
            ll mid=(ok+ng)/2;
            if(st.get(0,mid)>=Q[i].pos){
                ok=mid;
            }else ng=mid;
        }
        ans[Q[i].id]=a[ok];
    }
    rep(i,0,q-1)cout<<ans[i]<<endl;
    
    return 0;
}
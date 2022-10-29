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
    
    using T = ll;
    auto merge_values = [](T& a, T& b){return min(a, b);};
    T te = inf;
    
    return Segtree<T, decltype(merge_values)>
        (N, merge_values, te);
};
/*
auto st = make_segtree(n);
vector<ll> init(n);
st.build(init);
 */

ll n,m;
vector<string>s;
vector<vector<ll>>a;
bool hantei(ll T,bool print=false){
    bool f[n][m];memset(f,false,sizeof(f));
    rep(i,0,n-1){
        auto st = make_segtree(m);
        vector<ll>init(m);
        rep(j,0,m-1)init[j]=a[i][j];
        st.build(init);
        rep(j,0,m-T){
            if(st.get(j,j+T-1)>=T)f[i][j]=true;
        }
    }
    ll sm[n][m];memset(sm,0,sizeof(sm));
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(f[i][j]){
                sm[i][j]++;
                if(i+T<=n-1)sm[i+T][j]--;
                if(j+T<=m-1)sm[i][j+T]--;
                if(i+T<=n-1&&j+T<=m-1)sm[i+T][j+T]++;
            }
        }
    }
    rep(i,0,n-1)rep(j,0,m-2)sm[i][j+1]+=sm[i][j];
    rep(j,0,m-1)rep(i,0,n-2)sm[i+1][j]+=sm[i][j];
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(s[i][j]=='X'&&sm[i][j]<=0)return false;
        }
    }
    if(print==false)return true;
    bool ans[n][m];memset(ans,0,sizeof(ans));
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(f[i][j]){
                ans[i+T/2][j+T/2]=true;
            }
        }
    }
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(ans[i][j])cout<<"X";
            else cout<<".";
        }cout<<endl;
    }
    
    return true;
}

int main(){fastio
    cin>>n>>m;
    rep(i,0,n-1){
        string k;cin>>k;s.pb(k);
    }
    ll ok=0,ng=min(n,m);
    
    a.resize(n);
    rep(i,0,n-1)a[i].resize(m);
    rep(j,0,m-1){
        for(ll i=n-1;i>=0;i--){
            if(i!=n-1)a[i][j]=a[i+1][j];
            else a[i][j]=0;
            if(s[i][j]=='X')a[i][j]++;
            else a[i][j]=0;
        }
    }
    /*
    rep(i,0,n-1){
        rep(j,0,m-1){
            cout<<s[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    rep(i,0,n-1){
        rep(j,0,m-1){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;*/
    
    
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        ll T=mid*2+1;
        if(hantei(T))ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    hantei(2*ok+1,true);
    return 0;
}
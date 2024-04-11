#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define rrep2(i,n,k) for(int (i)=(n)-1;(i)>=(n)-(k);(i)--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

//vector output
template <typename T>
void out(vector<T> &v){
    for(T x:v) cout << x << " ";
    cout << "\n"; return;
}
//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    graph(long long n,long long m,bool weighted = false,bool directed = false) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
        for(int i=0;i<m;i++){
            long long a,b,c; cin >> a >> b;
            if(weighted) cin >> c;
            else c = 1;
            unite(a,b,c,directed);
        }
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};
//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

const ll mod = 998244353;

//segment tree
//1-indexed all
class lazy_segtree {
public:
    ll n;
    vector<ll> A,C,P,A_lazy,C_lazy,P_lazy; //P=A*C
    lazy_segtree(ll k){
        n = 1;
        while(n<k){ n *= 2; }
        A=vector<ll>(2*n,0); C=vector<ll>(2*n,0); P=vector<ll>(2*n,0);
        A_lazy=vector<ll>(2*n,0); C_lazy=vector<ll>(2*n,0); P_lazy=vector<ll>(2*n,0);
    }

    void eval(ll k){
        A[k] += A_lazy[k]; 
        C[k] += C_lazy[k]; 
        P[k] += P_lazy[k]; 
        if(k<n){
            A_lazy[2*k] += A_lazy[k]/2LL; A_lazy[2*k+1] += A_lazy[k]/2LL; 
            C_lazy[2*k] += C_lazy[k]/2LL; C_lazy[2*k+1] += C_lazy[k]/2LL;
            if(P_lazy[k]!=0){ 
                P_lazy[2*k] += P_lazy[k]*(C[2*k]+C_lazy[2*k])/(C[2*k]+C_lazy[2*k]+C[2*k+1]+C_lazy[2*k+1]);
                P_lazy[2*k+1] += P_lazy[k]*(C[2*k+1]+C_lazy[2*k+1])/(C[2*k]+C_lazy[2*k]+C[2*k+1]+C_lazy[2*k+1]);
            }
        }
        A_lazy[k] = 0; C_lazy[k] = 0; P_lazy[k] = 0;
    }
 
    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        return rangesum(i,j,1,1,n);
    }
 
    // a,b k c,d(k=1,c=1,d=n)
    ll rangesum(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 0;
        eval(k);
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return P[k];
        }
        else{
            //2
            ll p = rangesum(a,b,k*2,c,(c+d)/2)+rangesum(a,b,k*2+1,(c+d)/2+1,d);
            return p;
        }
    }

    //a[i]+a[i+1]++a[j]
    ll count(ll i,ll j){
        return rangecnt(i,j,1,1,n);
    }
 
    // a,b k c,d(k=1,c=1,d=n)
    ll rangecnt(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 0;
        eval(k);
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return C[k];
        }
        else{
            //2
            ll p = rangecnt(a,b,k*2,c,(c+d)/2)+rangecnt(a,b,k*2+1,(c+d)/2+1,d);
            return p;
        }
    }

    void add_a(ll i,ll j,ll x){
        rangeadd_a(i,j,1,1,n,x);
    }

    // a,b k c,d(k=1,c=1,d=n)
    void rangeadd_a(ll a,ll b,ll k,ll c,ll d,ll x){
        //
        ll el = 0;
        eval(k);
        if(d<a||b<c){
        }
        else if(a<=c&&d<=b){
            A_lazy[k] += (d-c+1)*x;
            P_lazy[k] += C[k]*x;
        }
        else{
            //2
            rangeadd_a(a,b,k*2,c,(c+d)/2,x); rangeadd_a(a,b,k*2+1,(c+d)/2+1,d,x);
            A[k] = A[2*k]+A[2*k+1]+A_lazy[2*k]+A_lazy[2*k+1];
            P[k] = P[2*k]+P[2*k+1]+P_lazy[2*k]+P_lazy[2*k+1];
            C[k] = C[2*k]+C[2*k+1]+C_lazy[2*k]+C_lazy[2*k+1];
        }
        return;
    }

    void add_c(ll i,ll j,ll x){
        rangeadd_c(i,j,1,1,n,x);
    }

    // a,b k c,d(k=1,c=1,d=n)
    void rangeadd_c(ll a,ll b,ll k,ll c,ll d,ll x){
        //
        ll el = 0;
        eval(k);
        if(d<a||b<c){
            return;
        }
        else if(a<=c&&d<=b){
            C_lazy[k] += (d-c+1)*x;
            P_lazy[k] += A[k]*x;
            return;
        }
        else{
            //2
            rangeadd_c(a,b,k*2,c,(c+d)/2,x); rangeadd_c(a,b,k*2+1,(c+d)/2+1,d,x);
            C[k] = C[2*k]+C[2*k+1]+C_lazy[2*k]+C_lazy[2*k+1];
            P[k] = P[2*k]+P[2*k+1]+P_lazy[2*k]+P_lazy[2*k+1];
            A[k] = A[2*k]+A[2*k+1]+A_lazy[2*k]+A_lazy[2*k+1];
            return;
        }
    }
 
};
 

int main(){
	riano_; ll ans = 0;
    ll Q,D; cin >> Q >> D;
    lazy_segtree L(2e5+2);
    lazy_segtree R(2e5+2);
    rep(i,Q){
        ll a; cin >> a;
        if(L.count(a,a)==0){
            ll s = R.count(a+1,a+D); ans += s*(s-1)/2LL;
            ll t = L.count(a-D,a-1); ans += t*(t-1)/2LL;
            ans += L.sum(1,a-1)-R.sum(1,a-1);
            L.add_a(a-D,a-1,1); L.add_c(a,a,1);
            R.add_a(a+1,a+D,1); R.add_c(a,a,1);
        }
        else{
            ll s = R.count(a+1,a+D); ans -= s*(s-1)/2LL;
            ll t = L.count(a-D,a-1); ans -= t*(t-1)/2LL;
            L.add_a(a-D,a-1,-1); L.add_c(a,a,-1);
            R.add_a(a+1,a+D,-1); R.add_c(a,a,-1);
            ans -= L.sum(1,a-1)-R.sum(1,a-1);
        }
        cout << ans << "\n";
    }
    //cout << ans << endl;
}
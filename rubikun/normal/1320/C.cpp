#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

struct data{
    ll x;
    ll y;
    ll coin;
};

template<typename T,typename E>
struct LazySegmentTree{
    using F=function<T(T,T)>;
    using G=function<T(T,E)>;
    using H=function<E(E,E)>;
    
    int n;
    vector<T> dat;
    vector<E> lazy;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    
    LazySegmentTree(int n_,F f,G g,H h,T ti,E ei) :f(f),g(g),h(h),ti(ti),ei(ei){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        lazy.assign(2*n-1,ei);
    }
    
    LazySegmentTree(int n_,vector<T> &v,F f,G g,H h,T ti,E ei) :f(f),g(g),h(h),ti(ti),ei(ei){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        
        for(int i=n-1;i-(n-1)<v.size();i++) dat[i]=v[i-(n-1)];
        
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
        
        lazy.assign(2*n-1,ei);
    }
    
    inline void eval(int k,int l,int r){
        
        if(lazy[k]==ei) return;
        
        dat[k]=g(dat[k],lazy[k]);
        
        if(r-l>1){
            lazy[k*2+1]=h(lazy[k*2+1],lazy[k]);
            lazy[k*2+2]=h(lazy[k*2+2],lazy[k]);
        }
        
        lazy[k]=ei;
    }
    
    void update_(int a,int b,E x,int k,int l,int r){
        
        eval(k,l,r);
        
        if(r<=a||b<=l) return;
        
        if(a<=l&&r<=b){
            lazy[k]=h(lazy[k],x);
            eval(k,l,r);
        }
        
        else{
            update_(a,b,x,2*k+1,l,(l+r)/2);
            update_(a,b,x,2*k+2,(l+r)/2,r);
            dat[k]=f(dat[2*k+1],dat[2*k+2]);
        }
        
    }
    
    void update(int a,int b,E x){
        return update_(a,b,x,0,0,n);
    }
    
    T query_(int a,int b,int k,int l,int r){
        
        eval(k,l,r);
        
        if(r<=a||b<=l) return ti;
        if(a<=l&&r<=b) return dat[k];
        
        T vl=query_(a,b,2*k+1,l,(l+r)/2);
        T vr=query_(a,b,2*k+2,(l+r)/2,r);
        return f(vl,vr);
    }
    
    T query(int a,int b){
        return query_(a,b,0,0,n);
    }
    
};

//Tpair<ll,int>a

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,P;cin>>N>>M>>P;
    vector<pair<ll,ll>> A(N),B(M);
    vector<data> C(P);
    
    for(int i=0;i<N;i++) cin>>A[i].first>>A[i].second;
    for(int i=0;i<M;i++) cin>>B[i].first>>B[i].second;
    for(int i=0;i<P;i++) cin>>C[i].x>>C[i].y>>C[i].coin;
    
    sort(all(A));
    sort(all(C),[](data a,data b){
        return a.x<b.x;
    });
    
    vector<ll> def(1000005,-INF);
    
    for(int i=0;i<M;i++){
        def[B[i].first]=max(def[B[i].first],-B[i].second);
    }
    
    for(int i=1000003;i>=0;i--) def[i]=max(def[i],def[i+1]);
    
    LazySegmentTree<ll,ll> seg(1000005,
                               def,
                               [](ll a,ll b){return max(a,b);},
                               [](ll a,ll b){return a+b;},
                               [](ll a,ll b){return a+b;},
                               -INF,
                               0);
    
    ll ans=-INF;
    int now=0;
    
    for(int i=0;i<N;i++){
        while(now<P&&C[now].x<A[i].first){
            seg.update(C[now].y+1,1000005,C[now].coin);
            now++;
        }
        ans=max(ans,-A[i].second+seg.query(0,1000005));
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}
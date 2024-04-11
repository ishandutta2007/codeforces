#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;
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
    
    int N,M,K;cin>>N>>M>>K;
    vector<vector<int>> S(N+1,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>S[i][j];
        }
    }
    
    LazySegmentTree<int,int> seg(M,
                                 [](int a,int b){return max(a,b);},
                                 [](int a,int b){return a+b;},
                                 [](int a,int b){return a+b;},
                                 0,
                                 0);
    
    for(int i=0;i<N;i++){
        vector<int> save(M),sum(M+1);
        
        for(int j=1;j<=M;j++){
            sum[j]=sum[j-1]+S[i][j-1]+S[i+1][j-1];
        }
        if(i){
            for(int j=0;j<K;j++){
                seg.update(0,j+1,-S[i][j]);
            }
        }
        
        for(int j=0;j<=M-K;j++){
            save[j]=seg.query(0,M)+sum[j+K]-sum[j];
            
            if(i){
                seg.update(max(0,j-K+1),j+1,S[i][j]);
                if(j<M-K) seg.update(j+1,j+K+1,-S[i][j+K]);
            }
        }
        
        for(int j=0;j<M;j++){
            int a=seg.query(j,j+1);
            seg.update(j,j+1,-a+save[j]);
            
            //cout<<seg.query(j,j+1)<<" ";
        }
        //cout<<endl;
    }
    
    cout<<seg.query(0,M)<<endl;
}
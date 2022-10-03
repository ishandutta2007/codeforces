#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

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
    
    auto f=[&](int a,int b){
        return a^b;
    };
    
    auto g=[&](int a,pair<int,int> b){
        if(b.second==0){
            return a^(b.first);
        }else{
            return b.first;
        }
    };
    
    auto h=[&](pair<int,int> a,pair<int,int> b){
        if(b.second==0){
            if(a.second==0) return make_pair(a.first^b.first,0);
            else return make_pair(a.first^b.first,1);
        }else{
            if(a.second==0) return make_pair(b.first,1);
            else return make_pair(b.first,1);
        }
    };
    
    int N,Q;cin>>N>>Q;
    
    LazySegmentTree<int,pair<int,int>> seg(100001,
                                           f,
                                           g,
                                           h,
                                           0,
                                           make_pair(0,0)
                                           );
    //0,1,2,3
    
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    while(Q--){
        string A;
        int B;cin>>A>>B;
        
        if(A==">"){
            if(B>=0){
                seg.update(abs(B)+1,100001,make_pair(3,1));
            }else{
                seg.update(0,abs(B),make_pair(1,0));
                seg.update(abs(B),100001,make_pair(3,1));
            }
        }else{
            if(B>=0){
                seg.update(0,abs(B),make_pair(1,0));
                seg.update(abs(B),100001,make_pair(2,1));
            }else{
                seg.update(abs(B)+1,100001,make_pair(2,1));
            }
        }
    }
    
    for(int i=0;i<N;i++){
        int a=seg.query(abs(A[i]),abs(A[i])+1);
        if(a==0) cout<<A[i]<<" ";
        else if(a==1) cout<<-A[i]<<" ";
        else if(a==2) cout<<abs(A[i])<<" ";
        else if(a==3) cout<<-abs(A[i])<<" ";
    }
    cout<<endl;
    
    
    
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2000005,INF=1<<30;
 
template<typename T,typename E,typename F,typename F2,typename G,typename H>
struct LazySegmentTree{
    //using F=function<T(T,T)>;
    //using F2=function<T(T,T)>;
    //using G=function<T(T,E)>;
    //using H=function<E(E,E)>;
    
    int n;
    vector<T> dat,dat2;
    vector<E> lazy;
    F f;
    F2 f2;
    G g;
    H h;
    T ti;
    T ti2;
    E ei;
    
    LazySegmentTree(int n_,F f,F2 f2,G g,H h,T ti,T ti2,E ei) :f(f),f2(f2),g(g),h(h),ti(ti),ti2(ti2),ei(ei){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        dat2.assign(2*n-1,ti2);
        lazy.assign(2*n-1,ei);
    }
    
    LazySegmentTree(int n_,vector<T> &v,F f,F2 f2,G g,H h,T ti,T ti2,E ei) :f(f),f2(f2),g(g),h(h),ti(ti),ti2(ti2),ei(ei){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        dat2.assign(2*n-1,ti2);
        
        for(int i=n-1;i-(n-1)<v.size();i++){
            dat[i]=v[i-(n-1)];
            dat2[i]=v[i-(n-1)];
        }
        
        for(int i=n-2;i>=0;i--){
            dat[i]=f(dat[i*2+1],dat[i*2+2]);
            dat2[i]=f2(dat2[i*2+1],dat2[i*2+2]);
        }
        
        lazy.assign(2*n-1,ei);
    }
    
    inline void eval(int k,int l,int r){
        
        if(lazy[k]==ei) return;
        
        dat[k]=g(dat[k],lazy[k]);
        dat2[k]=g(dat2[k],lazy[k]);
        
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
            dat2[k]=f2(dat2[2*k+1],dat2[2*k+2]);
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
    
    T query2_(int a,int b,int k,int l,int r){
        
        eval(k,l,r);
        
        if(r<=a||b<=l) return ti2;
        if(a<=l&&r<=b) return dat2[k];
        
        T vl=query2_(a,b,2*k+1,l,(l+r)/2);
        T vr=query2_(a,b,2*k+2,(l+r)/2,r);
        return f2(vl,vr);
    }
    
    T query2(int a,int b){
        return query2_(a,b,0,0,n);
    }
    
    
    
};
 
int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    int now=0;
    string S;cin>>S;
    string T;
    for(int i=0;i<N+3;i++) T+='Q';
    
    vector<int> def(N+3,0);
    
    auto f=[&](int a,int b){return max(a,b);};
    auto f2=[&](int a,int b){return min(a,b);};
    auto g=[&](int a,int b){return a+b;};
    auto h=[&](int a,int b){return a+b;};
    
    LazySegmentTree<int,int,decltype(f),decltype(f2),decltype(g),decltype(h)> seg(N+3,
                                 def,
                                 f,
                                 f2,
                                 g,
                                 h,
                                 -INF,
                                 INF,
                                 0);
    
    for(int i=0;i<N;i++){
        if(S[i]=='L'){
            if(now>0) now--;
        }
        else if(S[i]=='R') now++;
        else if(S[i]=='('){
            if(T[now]=='(') now+=0;
            else if(T[now]==')'){
                seg.update(now,N+3,2);
                T[now]='(';
            }else{
                seg.update(now,N+3,1);
                T[now]='(';
            }
        }else if(S[i]==')'){
            if(T[now]==')') now+=0;
            else if(T[now]=='('){
                seg.update(now,N+3,-2);
                T[now]=')';
            }else{
                seg.update(now,N+3,-1);
                T[now]=')';
            }
        }else{
            if(T[now]=='('){
                seg.update(now,N+3,-1);
                T[now]='Q';
            }else if(T[now]==')'){
                seg.update(now,N+3,1);
                T[now]='Q';
            }
        }
        //cout<<now<<endl;
        
        if(seg.query(N+1,N+2)==0&&seg.query2(0,N+3)>=0){
            cout<<seg.query(0,N+3)<<" ";
        }else cout<<-1<<" ";
    }
    cout<<"\n";
}
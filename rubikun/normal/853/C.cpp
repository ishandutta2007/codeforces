#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=3005;
const ll INF=1LL<<40;
template<typename T>
struct SegmentTree{
    using F=function<T(T,T)>;
    
    int n;
    vector<T> dat;
    F f;
    T ti;
    
    SegmentTree(int n_ ,F f ,T ti) :f(f),ti(ti){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
    }
    
    SegmentTree(int n_ ,vector<T> &v ,F f,T ti) :f(f),ti(ti){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        
        for(int i=n-1;i-(n-1)<v.size();i++) dat[i]=v[i-(n-1)];
        
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    
    void update(int k,T x){
        k+=n-1;
        dat[k]=x;
        
        while(k){
            k=(k-1)/2;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }
    
    void set(int k,T x){
        dat[n-1+k]=x;
    }
    
    void built(){
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    
    T query_(int a,int b,int k,int l,int r){
        if(a==b) return ti;
        if(r<=a||b<=l) return ti;
        if(a<=l&&r<=b) return dat[k];
        else{
            T vl=query_(a,b,2*k+1,l,(l+r)/2);
            T vr=query_(a,b,2*k+2,(l+r)/2,r);
            return f(vl,vr);
        }
    }
    
    T query(int a,int b){
        return query_(a,b,0,0,n);
    }
    
    T get(int k){
        return dat[k+n-1];
    }
    
    template<typename C>
    int findright(int st,C &check,T &acc,int k,int l,int r){
        if(l+1==r){
            acc=f(acc,dat[k]);
            return check(acc)?k-(n-1):-1;
        }
        int m=(l+r)/2;
        if(m<=st) return findright(st,check,acc,2*k+2,m,r);
        if(st<=l&&!check(f(acc,dat[k]))){
            acc=f(acc,dat[k]);
            return -1;
        }
        int vl=findright(st,check,acc,2*k+1,l,m);
        if(~vl) return vl;
        return findright(st,check,acc,2*k+2,m,r);
    }
    
    template<typename C>
    int findright(int st,C &check){
        T acc=ti;
        return findright(st,check,acc,0,0,n);
    }//idx
    
    template<typename C>
    int findleft(int st,C &check,T &acc,int k,int l,int r){
        if(l+1==r){
            acc=f(acc,dat[k]);
            return check(acc)?k-(n-1):INF;
        }
        int m=(l+r)/2;
        if(m>=st) return findleft(st,check,acc,2*k+1,l,m);
        if(st>=r&&!check(f(acc,dat[k]))){
            acc=f(acc,dat[k]);
            return INF;
        }
        int vr=findleft(st,check,acc,2*k+2,m,r);
        if(vr!=INF) return vr;
        return findleft(st,check,acc,2*k+1,l,m);
    }
    
    template<typename C>
    int findleft(int st,C &check){
        T acc=ti;
        return findleft(st,check,acc,0,0,n);
    }//idx
    
};

struct dat{
    ll u;
    ll d;
    ll l;
    ll r;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,Q;cin>>N>>Q;
    vector<ll> A(N),ans(Q);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        a--;
        A[N-1-a]=i;
    }
    
    vector<dat> S,T;
    
    for(int i=0;i<Q;i++){
        ll u,d,l,r;
        cin>>l>>d>>r>>u;
        d=N+1-d;
        u=N+1-u;
        u--;d--;l--;r--;
        
        ans[i]+=u*(u-1)/2;
        ans[i]+=l*(l-1)/2;
        ans[i]+=(N-1-d)*(N-1-d-1)/2;
        ans[i]+=(N-1-r)*(N-1-r-1)/2;
        
        S.push_back(dat{0,u-1,l,r,i});
        T.push_back(dat{d+1,N-1,l,r,i});
    }
    
    sort(all(S),[](auto a,auto b){return a.d<b.d;});
    sort(all(T),[](auto a,auto b){return a.u>b.u;});
    
    SegmentTree<int> seg(N,
                         [](auto a,auto b){return a+b;},
                         0);
    
    int id=0;
    
    while(id<Q&&S[id].d<0) id++;
    
    for(int i=0;i<N;i++){
        seg.update(A[i],1);
        while(id<Q&&S[id].d==i){
            ll x;
            
            x=seg.query(0,S[id].l);
            ans[S[id].id]-=x*(x-1)/2;
            
            x=seg.query(S[id].r+1,N);
            ans[S[id].id]-=x*(x-1)/2;
            
            id++;
        }
    }
    
    id=0;
    
    while(id<Q&&T[id].u>=N) id++;
    
    for(int i=0;i<N;i++) seg.update(i,0);
    
    for(int i=N-1;i>=0;i--){
        seg.update(A[i],1);
        while(id<Q&&T[id].u==i){
            ll x;
            
            x=seg.query(0,T[id].l);
            ans[T[id].id]-=x*(x-1)/2;
            
            x=seg.query(T[id].r+1,N);
            ans[T[id].id]-=x*(x-1)/2;
            
            id++;
        }
    }
    
    for(int i=0;i<Q;i++){
        cout<<N*(N-1)/2-ans[i]<<"\n";
    }
    
}
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
const int mod=1000000007,MAX=5005;
const ll INF=1LL<<50;

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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N),def1(N+1),def2(N+1);
        ll sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(i%2==0){
                sum+=A[i];
                def1[i+1]=def1[i]-A[i];
            }else{
                def1[i+1]=def1[i]+A[i];
            }
        }
        
        def2=def1;
        
        for(int i=0;i<=N;i++){
            //if(N==10) cout<<def1[i]<<" ";
            if(i&1) def2[i]=-INF;
            else def1[i]=-INF;
        }
        
        SegmentTree<ll> seg1(N+1,
                            def1,
                            [](auto a,auto b){return max(a,b);},
                            -INF);
        SegmentTree<ll> seg2(N+1,
                             def2,
                             [](auto a,auto b){return max(a,b);},
                             -INF);
        
        ll ans=sum;
        
        //cout<<ans<<" ";
        
        for(int i=0;i<N;i++){
            if((i&1)==0){
                ll a=seg2.query(i,N+1)-seg2.get(i);
                chmax(ans,sum+a);
            }else{
                ll a=seg1.query(i,N+1)-seg1.get(i);
                chmax(ans,sum+a);
            }
        }
        
        cout<<ans<<"\n";
    }
}
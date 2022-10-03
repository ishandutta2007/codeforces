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
const int mod=1000000007,MAX=200005,INF=1<<30;

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
    
    int N,Q;cin>>N>>Q;
    vector<ll> pos(N);
    vector<ll> w(N);
    
    for(int i=0;i<N;i++){
        cin>>pos[i];
        pos[i]-=i;
    }
    
    for(int i=0;i<N;i++){
        cin>>w[i];
    }
    
    SegmentTree<pair<ll,ll>> seg(N,
                                 [](pair<ll,ll> a,pair<ll,ll> b){
                                     ll x=a.fi+b.fi,y=a.se+b.se;
                                     if(x>=mod) x-=mod;
                                     if(y>=mod) y-=mod;
                                     return mp(x,y);},
                                 mp(0,0));
    
    SegmentTree<ll> wsum(N,
                         w,
                         [](ll a,ll b){return a+b;},
                         0);
    
    for(int i=0;i<N;i++){
        seg.update(i,mp(w[i]*pos[i]%mod,(w[i]*(mod-pos[i]))%mod));
    }
    
    while(Q--){
        ll l,r;cin>>l>>r;
        if(l<0){
            l*=-1;
            l--;
            seg.update(l,mp(r*pos[l]%mod,(r*(mod-pos[l]))%mod));
            wsum.update(l,r);
            w[l]=r;
        }else{
            l--;
            r--;
            
            ll left=l,right=r+1;
            
            ll sum=wsum.query(left,right);
            
            auto check=[&](ll x){return 2*x>=sum;};
            int d=wsum.findright(l,check);
            
            ll lsum=0,rsum=0;
            
            lsum+=seg.query(l,d).se-(wsum.query(l,d)%mod*(mod-pos[d]))%mod;
            rsum+=seg.query(d,r+1).fi-wsum.query(d,r+1)%mod*pos[d]%mod;
            
            ll ans=lsum+rsum;
            while(ans<mod) ans+=mod;
            while(ans>=mod) ans-=mod;
            cout<<ans<<"\n";
        }
    }
}
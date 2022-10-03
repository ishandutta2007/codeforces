#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
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
    
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    vector<int> P(N),A(M),whe(N),now(N,-1),from(M,-1);//whe[i]==j ... ij
    vector<vector<int>> par(M,vector<int>(19,-1));
    for(int i=0;i<N;i++){
        cin>>P[i];
        P[i]--;
        whe[P[i]]=i;
    }
    for(int i=0;i<M;i++){
        cin>>A[i];
        A[i]--;
    }
    
    for(int i=0;i<M;i++){
        int a=whe[A[i]];
        now[a]=i;
        
        a=(N+a-1)%N;
        par[i][0]=now[a];
    }
    
    for(int j=1;j<19;j++){
        for(int i=0;i<M;i++){
            if(par[i][j-1]==-1) continue;
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    
    for(int i=0;i<M;i++){
        int rem=N-1,now=i;
        for(int j=18;j>=0;j--){
            if(rem&(1<<j)){
                rem-=(1<<j);
                now=par[now][j];
            }
            if(now==-1) break;
        }
        from[i]=now;
    }
    
    SegmentTree<int> seg(M,
                         from,
                         [](int a,int b){return max(a,b);},
                         -1);
    
    while(Q--){
        int L,R;cin>>L>>R;
        L--;
        if(seg.query(L,R)>=L) cout<<1;
        else cout<<0;
        
    }
    cout<<endl;
    
}
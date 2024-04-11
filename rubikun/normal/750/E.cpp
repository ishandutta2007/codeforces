#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=605,INF=1<<29;

typedef array<array<int,5>,5> mat;

template<typename T,typename F>
struct SegmentTree{
    //using F=function<T(T,T)>;
    
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

mat add(mat &a, mat &b){
    mat c={};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            c[i][j]=INF;
        }
    }
    for(int i=0;i<5;i++){
        for(int k=0;k<5;k++){
            for(int j=0;j<5;j++){
                c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    
    return c;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    
    mat ti={};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            ti[i][j]=INF;
        }
        ti[i][i]=0;
    }
    
    auto f=[&](mat a,mat b){return add(a,b);};
    
    SegmentTree<mat,decltype(f)> seg(N,
                         f,
                         ti);
    
    mat mm={};
    for(int a=0;a<5;a++){
        for(int b=0;b<5;b++){
            mm[a][b]=INF;
        }
        mm[a][a]=0;
    }
    
    for(int i=0;i<N;i++){
        mat m=mm;
        if(S[i]=='2'){
            m[0][0]=1;
            m[0][1]=0;
        }else if(S[i]=='0'){
            m[1][1]=1;
            m[1][2]=0;
        }else if(S[i]=='1'){
            m[2][2]=1;
            m[2][3]=0;
        }else if(S[i]=='7'){
            m[3][3]=1;
            m[3][4]=0;
        }else if(S[i]=='6'){
            m[3][3]=1;
            m[4][4]=1;
        }
        
        seg.set(i,m);
        
    }
    
    seg.built();
    
    for(int i=0;i<Q;i++){
        int l,r;cin>>l>>r;
        l--;
        if(seg.query(l,r)[0][4]>=INF) cout<<-1<<"\n";
        else cout<<seg.query(l,r)[0][4]<<"\n";
    }
}
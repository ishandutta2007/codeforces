#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;
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
    
    int N,M,K;cin>>N>>M>>K;
    vector<vector<int>> S(N+1,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>S[i][j];
        }
    }
    
    SegmentTree<int> seg(M,
                         [](int a,int b){return max(a,b);},
                         0);
    
    for(int i=0;i<N;i++){
        vector<int> save(M),sum1(M+1),sum2(M+1);
        
        for(int j=1;j<=M;j++){
            sum1[j]=sum1[j-1]+S[i][j-1];
            sum2[j]=sum2[j-1]+S[i+1][j-1];
        }
        
        for(int j=0;j<=M-K;j++){
            int ma=0;
            ma=max(ma,seg.query(0,j-K+1));
            ma=max(ma,seg.query(j+K,M));
            
            ma+=sum1[j+K]-sum1[j]+sum2[j+K]-sum2[j];
            
            for(int u=max(0,j-K+1);u<=j;u++){
                int s=seg.get(u);
                s+=sum1[j+K]-sum1[u+K]+sum2[j+K]-sum2[j];
                
                ma=max(ma,s);
            }
            
            for(int u=j+1;u<j+K;u++){
                int s=seg.get(u);
                s+=sum1[u]-sum1[j]+sum2[j+K]-sum2[j];
                
                ma=max(ma,s);
            }
            
            save[j]=ma;
        }
        
        for(int j=0;j<M;j++) seg.set(j,save[j]);
        seg.built();
    }
    
    cout<<seg.query(0,M)<<endl;
}
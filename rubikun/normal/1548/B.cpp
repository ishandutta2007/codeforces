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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

template<typename T>
struct SparseTable{
    using F=function<T(T,T)>;
    
    int n,logn;
    vector<vector<T>> dat;
    vector<int> loglen;
    F f;
    T ti;
    
    SparseTable(int n_,F f,T ti) :f(f),ti(ti){
        n=1;
        logn=1;
        while(n<n_){
            n*=2;
            logn++;
        }
        loglen.resize(n+3);
        n=n_;
        int j=0;
        for(int i=1;i<n+3;i++){
            loglen[i]=j;
            if(i+1>(1<<(j+1))) j++;
        }
        
        dat.resize(logn);
        
        for(int i=0;i<logn;i++){
            dat[i].assign(n+1,ti);
        }
    }
    
    void set(vector<T> &v){
        for(int j=0;j<n+1;j++){
            if(j<si(v)) dat[0][j]=v[j];
        }
    }
    
    void set(int j,T x){
        dat[0][j]=x;
    }
    
    void built(){
        for(int i=1;i<logn;i++){
            for(int j=0;j<n+1;j++){
                T vl=dat[i-1][j],vr;
                if(j+(1<<(i-1))>=n+1) vr=ti;
                else vr=dat[i-1][j+(1<<(i-1))];
                dat[i][j]=f(vl,vr);
            }
        }
    }
    
    T query(int l,int r){
        //if(l>=r) return ti;
        T vl=dat[loglen[r-l]][l],vr=dat[loglen[r-l]][r-(1<<loglen[r-l])];
        return f(vl,vr);
    }
};

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        SparseTable<ll> spa(N-1,[](ll a,ll b){
            return gcd(a,b);
        },0);
        vector<ll> A(N),B(N-1);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N-1;i++) B[i]=abs(A[i+1]-A[i]);
        spa.set(B);
        spa.built();
        
        int ans=1,r=1;
        for(int l=0;l<N-1;l++){
            while(l>=r) r++;
            while(1){
                if(r==N) break;
                ll a=spa.query(l,r);
                if(a==1) break;
                chmax(ans,r-l+1);
                r++;
                if(r==N) break;
            }
            if(r==N) break;
        }
        
        cout<<ans<<"\n";
        
    }
}
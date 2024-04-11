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
const int mod=998244353,MAX=300005,INF=1<<30;

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
        T vl=dat[loglen[r-l]][l],vr=dat[loglen[r-l]][r-(1<<loglen[r-l])];
        return f(vl,vr);
    }
};

SparseTable<pair<int,int>> spa(MAX,
                              [](pair<int,int> a,pair<int,int> b){return min(a,b);},
                              mp(INF,INF));

int h[MAX];
ll x[MAX];

ll solve(int l,int r,int t){
    if(l>=r) return 0;
    auto m=spa.query(l,r);
    
    ll a=solve(l,m.se,t|1);
    chmax(a,0LL);
    
    ll b=solve(m.se+1,r,t|2);
    chmax(b,0LL);
    
    if(t==0) return x[m.se]+a+b;
    
    if(t==1) return max(a,x[m.se]+a+b);
    
    if(t==2) return max(b,x[m.se]+a+b);
    
    if(t==3) return max({a,b,x[m.se]+a+b});
    
    return 0LL;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>h[i];
        spa.set(i,mp(h[i],i));
    }
    spa.built();
    for(int i=0;i<N;i++){
        cin>>x[i];
    }
    
    cout<<solve(0,N,0)<<endl;
}
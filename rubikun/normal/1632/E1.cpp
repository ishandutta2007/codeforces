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
const int mod=998244353,MAX=300005,INF=1<<29;

const int MAX_LOG=20;
int parr[MAX_LOG][MAX],depth[MAX];
int N;
vector<int> G[MAX];

void init(int u){
    for(int i=0;i<N;i++){
        depth[i]=INF;
        for(int j=0;j<20;j++){
            parr[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int to:G[a]){
            if(chmin(depth[to],depth[a]+1)){
                parr[0][to]=a;
                Q.push(to);
            }
        }
    }
    
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(parr[k][i]<0) parr[k+1][i]=-1;
            else parr[k+1][i]=parr[k][parr[k][i]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth[v]-depth[u])>>i)&1) v=parr[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(parr[i][u]!=parr[i][v]){
            u = parr[i][u];
            v = parr[i][v];
        }
    }
    return parr[0][u];
}

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
        if(l>=r) return ti;
        T vl=dat[loglen[r-l]][l],vr=dat[loglen[r-l]][r-(1<<loglen[r-l])];
        return f(vl,vr);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        cin>>N;
        for(int i=0;i<=N;i++){
            for(int j=0;j<20;j++) parr[j][i]=-1;
            G[i].clear();
            depth[i]=0;
        }
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        init(0);
        pair<int,int> ma=mp(-1,-1);
        for(int i=0;i<N;i++) chmax(ma,mp(depth[i],i));
        int u=ma.se;
        vector<int> use;
        while(1){
            use.push_back(u);
            if(u==0) break;
            for(int to:G[u]){
                if(depth[to]+1==depth[u]){
                    //use.push_back(to);
                    u=to;
                    break;
                }
            }
        }
        
        reverse(all(use));
        
        u=ma.se;
        
        vector<int> T(N,-INF);
        for(int i=0;i<N;i++){
            int c=lca(i,u);
            chmax(T[c],depth[i]-depth[c]);
            //cout<<i<<" "<<c<<" "<<depth[i]-depth[c]<<endl;
        }
        
        SparseTable<int> s1(si(use),[&](int a,int b){return max(a,b);},-INF);
        SparseTable<int> s2(si(use),[&](int a,int b){return max(a,b);},-INF);
        
        vector<int> def1(si(use)),def2(si(use));
        for(int i=0;i<si(use);i++){
            def1[i]=depth[use[i]]+T[use[i]];
            def2[i]=-depth[use[i]]+T[use[i]];
            //cout<<depth[use[i]]<<" "<<T[use[i]]<<endl;
        }
        
        s1.set(def1);s1.built();
        s2.set(def2);s2.built();
        
        for(int x=1;x<=N;x++){
            if(x>=ma.fi){
                cout<<ma.fi<<" ";
                continue;
            }
            int left=x-1,right=ma.fi;
            while(right-left>1){
                int mid=(left+right)/2;
                int v=max(0,si(use)-1-(mid-x));
                int h=(v+x)/2;
                int res1=s1.query(0,min(v,h+1));
                int res2=s2.query(min(v,h)+1,v)+v+x;
                if(res1<=mid&&res2<=mid) right=mid;
                else left=mid;
            }
            cout<<right<<" ";
        }
        
        cout<<"\n";
    }
}
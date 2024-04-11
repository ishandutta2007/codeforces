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
const int mod=998244353,MAX=3005,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            //if(size[root(a)]<size[root(b)]) swap(a,b);
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<UF> X(30),Y(30);
    for(int i=0;i<30;i++){
        X[i].init(N);
        Y[i].init(N);
    }
    vector<int> guu(N),ok(N);
    vector<int> A(M),B(M),C(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        A[i]=a;B[i]=b;C[i]=c;
    }
    
    for(int j=0;j<30;j++){
        for(int i=0;i<M;i++){
            int a=A[i],b=B[i],c=C[i];
            
            if(c&(1<<j)) X[j].unite(a,b);
            
            if(c&1){
                if(c&(1<<j)) Y[j].unite(a,b);
            }else{
                guu[a]=true;
                guu[b]=true;
                ok[a]=true;
                ok[b]=true;
            }
        }
    }
    
    for(int j=1;j<30;j++){
        vector<int> ch(N);
        for(int i=0;i<N;i++){
            if(guu[i]){
                ch[Y[j].root(i)]=true;
            }
        }
        for(int i=0;i<N;i++){
            if(ok[i]) continue;
            if(ch[Y[j].root(i)]) ok[i]=true;
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int a,b;cin>>a>>b;a--;b--;
        bool f=false;
        for(int j=0;j<30;j++){
            f|=(X[j].check(a,b));
            if(f) break;
        }
        if(f){
            cout<<0<<"\n";
            continue;
        }
        if(ok[a]){
            cout<<1<<"\n";
        }else{
            cout<<2<<"\n";
        }
    }
}
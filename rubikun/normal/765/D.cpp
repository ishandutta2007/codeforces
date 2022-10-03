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
const int mod=1000000007,MAX=200005,INF=1<<28;

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
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
    
    int N;cin>>N;
    UF uf;uf.init(N);
    vector<int> f(N);
    for(int i=0;i<N;i++){
        cin>>f[i];f[i]--;
        uf.unite(i,f[i]);
    }
    int M=0;
    vector<int> id;
    for(int i=0;i<N;i++){
        if(uf.root(i)==i) id.push_back(i);
    }
    M=si(id);
    vector<int> g(N),h(M);
    for(int i=0;i<N;i++){
        g[i]=lower_bound(all(id),uf.root(i))-id.begin();
        h[g[i]]=f[i];
    }
    
    bool ok=true;
    for(int i=0;i<M;i++){
        if(g[h[i]]!=i) ok=false;
    }
    for(int i=0;i<N;i++){
        if(h[g[i]]!=f[i]) ok=false;
    }
    
    if(ok){
        cout<<M<<endl;
        for(int i=0;i<N;i++) cout<<g[i]+1<<" ";
        cout<<endl;
        for(int i=0;i<M;i++) cout<<h[i]+1<<" ";
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}
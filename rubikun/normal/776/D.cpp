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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

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
    UF uf;uf.init(2*M);
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    vector<vector<int>> B(N);
    for(int i=0;i<M;i++){
        int K;cin>>K;
        for(int j=0;j<K;j++){
            int x;cin>>x;
            x--;
            B[x].push_back(i);
        }
    }
    for(int i=0;i<N;i++){
        int a=B[i][0],b=B[i][1];
        if(A[i]){
            uf.unite(a,b);
            uf.unite(M+a,M+b);
        }else{
            uf.unite(a,M+b);
            uf.unite(b,M+a);
        }
    }
    for(int i=0;i<M;i++){
        if(uf.check(i,M+i)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
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

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
            if(i>=n/2) size[i]=1;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            if(root(a)%(n/2)>root(b)%(n/2)) swap(a,b);
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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        UF uf;uf.init(2*N);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;a--;b--;
            string S;cin>>S;
            if(S[0]=='c'){
                uf.unite(a,b);
                uf.unite(a+N,b+N);
            }else{
                uf.unite(a,b+N);
                uf.unite(a+N,b);
            }
        }
        
        bool ok=true;
        for(int i=0;i<N;i++){
            if(uf.check(i,N+i)) ok=false;
        }
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            if(uf.root(i)==i){
                ans+=max(uf.size[uf.root(i)],uf.size[uf.root(i+N)]);
            }
        }
        
        cout<<ans<<"\n";
        
    }
}
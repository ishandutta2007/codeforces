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
const int mod=1000000007,MAX=1005;
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
    UF uf;uf.init(2*N);
    UF ch;ch.init(N);
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(ch.check(a,b)){
            if(c==0){
                if(uf.check(a,b)){
                    cout<<0<<"\n";
                    return 0;
                }
            }else{
                if(uf.check(a,N+b)){
                    cout<<0<<"\n";
                    return 0;
                }
            }
        }else{
            if(c==0){
                uf.unite(a,N+b);
                uf.unite(b,N+a);
            }else{
                uf.unite(a,b);
                uf.unite(N+a,N+b);
            }
            ch.unite(a,b);
        }
    }
    
    ll ans=500000004;
    for(int i=0;i<N;i++){
        if(ch.root(i)==i) ans*=2;
        ans%=mod;
    }
    
    cout<<ans<<endl;
    
}
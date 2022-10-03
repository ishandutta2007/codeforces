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
const int mod=1000000007,MAX=300005;
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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        UF uf;uf.init(N);
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];A[i]--;
        }
        for(int i=0;i<N;i++){
            cin>>B[i];B[i]--;
            uf.unite(A[i],B[i]);
        }
        vector<int> aru(N);
        
        for(int i=0;i<N;i++){
            int x;cin>>x;
            if(x){
                x--;
                aru[uf.root(x)]=true;
            }
        }
        
        ll ans=1;
        
        for(int i=0;i<N;i++){
            if(uf.root(i)==i){
                if(!aru[i]){
                    ans*=min(2,uf.size[i]);
                    ans%=mod;
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}
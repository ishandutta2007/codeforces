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

struct UF{
    int n;
    vector<int> par,size;
    vector<ll> sum;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        sum.assign(n,0LL);
        
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
            sum[root(a)]+=sum[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

bool alive[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    UF uf;
    uf.init(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        uf.sum[i]=A[i];
    }
    
    vector<int> p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
        p[i]--;
    }
    
    ll ans=0;
    
    reverse(all(p));
    
    vector<ll> res(N);
    
    for(int i=0;i<N;i++){
        res[i]=ans;
        
        int a=p[i];
        if(a-1>=0&&alive[a-1]) uf.unite(a-1,a);
        if(a+1<N&&alive[a+1]) uf.unite(a,a+1);
        alive[a]=1;
        
        chmax(ans,uf.sum[uf.root(a)]);
    }
    
    reverse(all(res));
    
    for(int i=0;i<N;i++) cout<<res[i]<<"\n";
}
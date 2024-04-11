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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

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

ll deg[MAX];
bool check[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    UF uf;
    uf.init(N);
    ll cnt=0;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a==b){
            cnt++;
            check[a]=1;
            continue;
        }
        deg[a]++;
        deg[b]++;
        uf.unite(a,b);
    }
    
    set<int> se;
    for(int i=0;i<N;i++){
        if(uf.size[uf.root(i)]>=2||check[uf.root(i)]) se.insert(uf.root(i));
    }
    
    if(si(se)>=2){
        cout<<0<<endl;
        return 0;
    }
    
    ll ans=0;
    
    ans+=cnt*(M-cnt)+cnt*(cnt-1)/2;
    
    for(int i=0;i<N;i++){
        ans+=deg[i]*(deg[i]-1)/2;
    }
    
    cout<<ans<<endl;
}
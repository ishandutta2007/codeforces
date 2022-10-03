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
const int mod=998244353,MAX=300005;
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

vector<int> wh[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    UF uf;uf.init(N);
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].fi;
        A[i].se=i;
    }
    sort(all(A),[](auto a,auto b){
        return a.fi>b.fi;
    });
    
    vector<int> ok(N);
    
    int ma=0;
    
    for(auto a:A){
        ok[a.se]=true;
        if(a.se&&ok[a.se-1]) uf.unite(a.se,a.se-1);
        if(a.se+1<N&&ok[a.se+1]) uf.unite(a.se,a.se+1);
        chmax(ma,uf.size[uf.root(a.se)]);
        wh[ma].push_back(a.fi);
    }
    
    vector<int> ans(N+1);
    
    int can=0;
    for(int i=N;i>=1;i--){
        for(int a:wh[i]) chmax(can,a);
        ans[i]=can;
    }
    
    for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
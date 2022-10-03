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
const int mod=998244353,MAX=1000005,INF=1<<30;

//Union Find


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
    UF uf;uf.init(N);
    int can=0;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(uf.check(a,b)) can++;
        else uf.unite(a,b);
        vector<int> S;
        for(int j=0;j<N;j++){
            if(uf.root(j)==j) S.push_back(uf.size[j]);
        }
        sort(all(S));
        reverse(all(S));
        int sum=0;
        for(int j=0;j<min(si(S),can+1);j++) sum+=S[j];
        sum--;
        cout<<sum<<"\n";
    }
}
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
const int mod=998244353,MAX=300005,INF=1<<30;

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
        vector<int> P(N),to(N),inv(N),nxt(N);
        UF uf;uf.init(N);
        for(int i=0;i<N;i++){
            cin>>P[i];P[i]--;
            inv[P[i]]=i;
            uf.unite(i,P[i]);
            to[i]=i;
        }
        
        int ro=0;
        for(int i=0;i<N;i++){
            if(uf.root(i)==i) ro++;
        }
        
        for(int i=0;i+1<N;i++){
            if(!uf.check(i,i+1)){
                swap(to[i],to[i+1]);
                uf.unite(i,i+1);
            }
        }
        
        for(int i=0;i<N;i++){
            nxt[i]=inv[to[i]];
        }
        
        vector<int> ans;
        int now=0;
        for(int q=0;q<N;q++){
            now=nxt[now];
            ans.push_back(now);
        }
        
        /*
        for(int a:to) cout<<a+1<<" ";
        cout<<"\n";
        continue;
        */
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}
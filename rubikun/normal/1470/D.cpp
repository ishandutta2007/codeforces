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
const int mod=1000000007,MAX=300005,INF=1<<30;

vector<int> G[MAX];
int color[MAX];

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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        UF uf;
        uf.init(N);
        
        for(int i=0;i<N;i++){
            G[i].clear();
            color[i]=0;
        }
        
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            uf.unite(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        if(uf.size[uf.root(0)]!=N){
            cout<<"NO\n";
            continue;
        }
        
        cout<<"YES\n";
        
        queue<int> Q;
        color[0]=1;
        for(int to:G[0]){
            if(color[to]==0){
                color[to]=-1;
                Q.push(to);
            }
        }
        
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int to:G[u]){
                if(color[to]==0){
                    color[to]=1;
                    for(int toto:G[to]){
                        if(color[toto]==0){
                            color[toto]=-1;
                            Q.push(toto);
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<N;i++) if(color[i]==1) ans.push_back(i);
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}
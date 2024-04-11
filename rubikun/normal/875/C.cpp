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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void add_clause(int i,bool f,int j,bool g){
    add_edge(2*i+(!f),2*j+g);
    add_edge(2*j+(!g),2*i+f);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    V=2*M;
    vector<vector<int>> S(N);
    for(int i=0;i<N;i++){
        int K;cin>>K;
        S[i].resize(K);
        for(int j=0;j<K;j++){
            int x;cin>>x;x--;
            S[i][j]=x;
        }
    }
    
    vector<int> diff(N-1,-1);
    for(int i=0;i+1<N;i++){
        for(int j=0;j<min(si(S[i]),si(S[i+1]));j++){
            if(S[i][j]!=S[i+1][j]){
                int a=S[i][j],b=S[i+1][j];
                if(a<b){
                    add_edge(a,b);
                    add_edge(M+b,M+a);
                }else{
                    add_edge(a,M+a);
                    add_edge(M+b,b);
                }
                diff[i]=j;
                break;
            }
        }
        if(diff[i]==-1&&S[i]>S[i+1]){
            cout<<"No\n";
            return 0;
        }
    }
    
    scc();
    
    for(int i=0;i<M;i++){
        if(cmp[i]==cmp[M+i]){
            cout<<"No\n";
            return 0;
        }
    }
    
    cout<<"Yes\n";
    vector<int> ans;
    for(int i=0;i<M;i++){
        if(cmp[i]<cmp[M+i]) ans.push_back(i);
    }
    cout<<si(ans)<<"\n";
    for(int a:ans) cout<<a+1<<" ";
    cout<<"\n";
}
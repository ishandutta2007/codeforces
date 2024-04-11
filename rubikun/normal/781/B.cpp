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
const int mod=1000000007,MAX=2005,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void add_edge(int a,bool f,int b,bool g){
    add_edge(2*a+f,2*b+g);
}
//afbg

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
    
    int N;cin>>N;
    vector<string> A(N),B(N);
    for(int i=0;i<N;i++){
        string S,T;cin>>S>>T;
        A[i]=S.substr(0,3);
        B[i]=S.substr(0,2)+T[0];
        
        //cout<<A[i]<<" "<<B[i]<<endl;
    }
    
    V=2*N;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(A[i]==A[j]){
                //add_edge(i,0,j,1);
                //add_edge(j,0,i,1);
                
                add_clause(i,1,j,1);
            }
            if(A[i]==B[j]){
                //add_edge(i,0,j,0);
                //add_edge(j,1,i,1);
                
                add_clause(i,1,j,0);
            }
            if(B[i]==A[j]){
                //add_edge(i,1,j,1);
                //add_edge(j,0,i,0);
                
                add_clause(i,0,j,1);
            }
            if(B[i]==B[j]){
                //add_edge(i,1,j,0);
                //add_edge(j,1,i,0);
                
                add_clause(i,0,j,0);
            }
            
            if(A[i]==A[j]){
                //add_edge(i,1,j,1);
                //add_edge(j,1,i,1);
                
                add_clause(i,0,j,1);
                add_clause(j,0,i,1);
            }
        }
    }
    
    scc();
    
    for(int i=0;i<N;i++){
        if(cmp[2*i]==cmp[2*i+1]){
            cout<<"NO\n";
            return 0;
        }
    }
    
    cout<<"YES\n";
    
    for(int i=0;i<N;i++){
        if(cmp[2*i]>cmp[2*i+1]) cout<<A[i]<<"\n";
        else cout<<B[i]<<"\n";
    }
}
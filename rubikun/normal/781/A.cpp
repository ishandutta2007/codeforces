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

vector<int> G[MAX];
int color[MAX];

void DFS(int u,int p){
    int x=-1,y=-1;
    if(u!=-1) x=color[u];
    if(p!=-1) y=color[p];
    
    int now=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        while(now==x||now==y) now++;
        
        color[to]=now;
        now++;
        
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color[0]=1;
    DFS(0,-1);
    
    set<int> SE;
    for(int i=0;i<N;i++) SE.insert(color[i]);
    
    cout<<si(SE)<<endl;
    for(int i=0;i<N;i++) cout<<color[i]<<" ";
    cout<<endl;
}
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
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<int> G[MAX];
int color[MAX];
bool ok=true;

void DFS(int u){
    for(int to:G[u]){
        if(color[to]==0){
            color[to]=3-color[u];
            DFS(to);
        }else if(color[to]==color[u]) ok=false;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        if(color[i]==0){
            color[i]=1;
            DFS(i);
        }
    }
    
    if(!ok) cout<<-1<<endl;
    else{
        vector<int> A,B;
        for(int i=0;i<N;i++){
            if(color[i]==1) A.push_back(i+1);
            if(color[i]==2) B.push_back(i+1);
        }
        
        cout<<si(A)<<endl;
        for(int a:A) cout<<a<<" ";
        cout<<endl;
        cout<<si(B)<<endl;
        for(int a:B) cout<<a<<" ";
        cout<<endl;
        
    }
}
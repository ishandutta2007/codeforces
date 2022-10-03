#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=150005,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
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

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    init(N);
    for(int i=0;i<N;i++) G[i].push_back(i);
    
    for(int q=0;q<N-1;q++){
        int a,b;cin>>a>>b;
        a--;b--;
        a=root(a);
        b=root(b);
        if(size[a]<size[b]) swap(a,b);
        
        for(int i=0;i<G[b].size();i++){
            G[a].push_back(G[b][i]);
        }
        G[b].clear();
        unite(a,b);
    }
    
    for(int i=0;i<G[root(0)].size();i++){
        cout<<G[root(0)][i]+1<<" ";
    }
    cout<<endl;
}
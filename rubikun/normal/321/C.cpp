#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

struct edge{
    int to;
    int length;
};

int N;
vector<edge> G[MAX];

bool centroid[MAX];
int subtree_size[MAX];
char ans[MAX];

int compute_subtree_size(int u,int p){
    int c=1;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        c+=compute_subtree_size(a.to,u);
    }
    return subtree_size[u]=c;
}

pair<int,int> search_centroid(int u,int p,int t){
    pair<int,int> res={INF,-1};
    int s=1,m=0;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        
        res=min(res,search_centroid(a.to,u,t));
        
        m=max(m,subtree_size[a.to]);
        s+=subtree_size[a.to];
    }
    m=max(m,t-s);
    res=min(res,{m,u});
    return res;
}

void solve_subproblem(int u,int p){
    compute_subtree_size(u,-1);
    int s=search_centroid(u,-1,subtree_size[u]).second;
    centroid[s]=1;
    
    if(p==-1) ans[s]='A';
    else ans[s]=char(ans[p]+1);
    
    for(auto a:G[s]){
        if(centroid[a.to]) continue;
        solve_subproblem(a.to,s);
    }
    
    centroid[s]=0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    
    solve_subproblem(0,-1);
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}
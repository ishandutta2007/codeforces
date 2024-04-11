#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=500005,INF=1<<28;
vector<int> subG[MAX],G[MAX];
bool visited[MAX],app[MAX];
map<int,vector<int>> MA;
vector<int> ans;

void subDFS(int u,int p){
    visited[u]=1;
    for(int to:subG[u]){
        if(to==p) continue;
        if(visited[to]) continue;
        
        G[u].push_back(to);
        subDFS(to,u);
    }
}

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        vector<int> left,right;
        for(int to:G[a]){
            left.push_back(to);
            right.push_back(to);
            Q.push(to);
        }
        
        reverse(all(right));
        
        left.push_back(a);
        for(int b:right) left.push_back(b);
        
        MA[a]=left;
    }
}

inline void make(int u){
    for(auto it:MA[u]){
        if(it==u){
            ans.push_back(it);
            continue;
        }
        
        if(app[it]==0){
            app[it]=1;
            ans.push_back(it);
        }else{
            make(it);
        }
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
        subG[a].push_back(b);
        subG[b].push_back(a);
    }
    
    subDFS(0,-1);
    
    BFS(0);
    
    ans.push_back(0);
    app[0]=1;
    
    make(0);
    
    /*for(auto it:ans) cout<<it+1<<" ";
    cout<<endl;*/
    
    vector<vector<int>> seg(N,vector<int>(2));
    
    for(int i=0;i<2*N;i++){
        if(seg[ans[i]][0]==0) seg[ans[i]][0]=i+1;
        else seg[ans[i]][1]=i+1;
    }
    
    for(int i=0;i<N;i++){
        cout<<seg[i][0]<<" "<<seg[i][1]<<"\n";
    }
}
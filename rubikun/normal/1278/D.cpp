#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=500005,INF=1<<28;
vector<int> G[MAX];
bool visited[MAX];

void DFS(int u,int p){
    visited[u]=1;
    for(int to:G[u]){
        if(to==p) continue;
        if(visited[to]) continue;
        
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> S(2*N);
    vector<vector<int>> when(N,vector<int>(2));
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a]=i;
        S[b]=i;
        
        when[i][0]=a;
        when[i][1]=b;
    }
    
    set<pair<int,int>> SE;
    
    int cnt=0;
    
    for(int i=0;i<2*N;i++){
        if(i==when[S[i]][0]){
            SE.insert({i,S[i]});
        }else{
            auto it=SE.upper_bound({when[S[i]][0],S[i]});
            while(it!=SE.end()){
                cnt++;
                G[S[i]].push_back((*it).second);
                G[(*it).second].push_back(S[i]);
                it++;
            }
            SE.erase({when[S[i]][0],S[i]});
        }
        
        if(cnt>=N) break;
    }
    
    int c=0;
    
    for(int i=0;i<N;i++){
        if(visited[i]==0){
            DFS(i,-1);
            c++;
        }
    }
    
    if(cnt==N-1&&c==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
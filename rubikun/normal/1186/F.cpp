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
const ll mod=1000000007,MAX=1000005,INF=1<<30;
vector<pair<int,int>> G[MAX];
bool visited[2*MAX];

void DFS(int u, vector<int> &trail) {
    while(!G[u].empty()) {
        int v=G[u].back().fi,id=G[u].back().se;
        G[u].pop_back();
        
        if(visited[id]) continue;
        
        visited[id]=1;
        
        DFS(v,trail);
    }
    trail.push_back(u);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> cnt(N+1);
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
        cnt[a]++;
        cnt[b]++;
    }
    
    for(int i=1;i<=N;i++){
        if(cnt[i]%2){
            G[0].push_back(mp(i,M-1+i));
            G[i].push_back(mp(0,M-1+i));
            cnt[0]++;
            cnt[i]++;
        }
    }
    
    set<pair<int,int>> SE;
    
    for(int k=1;k<=N;k++){
        if(G[k].size()==0) continue;
        vector<int> trail;
        DFS(k,trail);
        vector<pair<int,int>> E;
        
        for(int i=0;i+1<trail.size();i++){
            E.push_back({trail[i],trail[i+1]});
        }
        E.push_back(E[0]);
        
        for(int i=0;i+1<E.size();i+=2){
            if(i==0) SE.insert(E[i]);
            else{
                if(E[i].first&&E[i].second) SE.insert(E[i]);
                else{
                    if(E[i-1].first&&E[i-1].second) SE.insert(E[i-1]);
                    else SE.insert(E[i+1]);
                }
            }
        }
    }
    
    cout<<SE.size()<<endl;
    for(auto a:SE) cout<<a.first<<" "<<a.second<<endl;
}
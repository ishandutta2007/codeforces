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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<int> alive(N,true);
    
    vector<int> er;
    
    for(int i=0;i<K;i++){
        int x;cin>>x;
        x--;alive[x]=false;
        er.push_back(x);
    }
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    set<pair<double,int>> SE;
    vector<int> adj(N);
    for(int i=0;i<N;i++){
        if(alive[i]){
            for(int to:G[i]){
                if(alive[to]) adj[i]++;
            }
            SE.insert(mp((double)(adj[i])/si(G[i]),i));
        }
    }
    
    pair<double,int> ans=mp(-1,-1);
    
    int t=0;
    
    while(si(SE)){
        chmax(ans,mp((*SE.begin()).fi,t));
        t++;
        int u=(*SE.begin()).se;
        er.push_back(u);
        SE.erase(SE.begin());
        alive[u]=false;
        for(int to:G[u]){
            if(alive[to]){
                SE.erase(mp((double)(adj[to])/si(G[to]),to));
                adj[to]--;
                SE.insert(mp((double)(adj[to])/si(G[to]),to));
            }
        }
    }
    
    vector<int> rec(N,true);
    for(int i=0;i<K+ans.se;i++) rec[er[i]]=false;
    cout<<N-(K+ans.se)<<"\n";
    for(int i=0;i<N;i++) if(rec[i]) cout<<i+1<<" ";
    cout<<"\n";
}
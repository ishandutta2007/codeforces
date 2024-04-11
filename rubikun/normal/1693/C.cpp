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
const int mod=998244353,MAX=200005,INF=1<<30;

vector<pair<int,int>> G[MAX],rG[MAX];
int dis[MAX],deg[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    map<pair<int,int>,int> MA;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        MA[mp(a,b)]++;
        deg[a]++;
    }
    
    for(auto e:MA){
        G[e.fi.fi].push_back(mp(e.fi.se,e.se));
        rG[e.fi.se].push_back(mp(e.fi.fi,e.se));
    }
    
    for(int i=0;i<N;i++) dis[i]=INF;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    dis[N-1]=0;PQ.push(mp(0,N-1));
    
    while(!PQ.empty()){
        auto [d,u]=PQ.top();PQ.pop();
        if(d>dis[u]) continue;
        for(auto [fr,cn]:rG[u]){
            deg[fr]-=cn;
            if(chmin(dis[fr],d+deg[fr]+1)) PQ.push(mp(dis[fr],fr));
        }
    }
    
    cout<<dis[0]<<endl;
}
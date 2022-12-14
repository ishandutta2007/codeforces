#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 300000+10;
int Que[Maxn];
int last;
int first=0;
int Vis[Maxn];
bool vis[Maxn];
int Dis[Maxn];
long long ans;
vector<int> al[Maxn];
int n,m;
int bfs(int v){
//  cerr << "Start" << endl;
    Dis[v] = 0;
    Vis[v] = 0;
    vis[v] = true;
    Que[last] = v;
    last++;
    while(last-first!=0){
        int u = Que[first];
        first++;
        if(Dis[u] >= 2)
            continue;
        for(int i = 0; i < al[u].size();i++){
            int next = al[u][i];
            if(next == v)
                continue;
            if(vis[next] == 0){
                Que[last] = next;
                last++;
                Dis[next]=Dis[u]+1;
            }
            vis[next] = true;
            if(u != v)
                Vis[next]++;
        //  cerr << u+1 << " " << next+1 << " " << endl;
        }
    }
    for(int i = 0; i < n;i++){
    //  cerr << v << " :) " << i << " Vis " << Vis[i] << endl;
        ans+=((long long)Vis[i]*(Vis[i]-1))/2;
        Vis[i] = 0;
        Dis[i] = 0;
        vis[i] = false;
    }
    last = 0;
    first = 0;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        al[--u].push_back(--v);
    }
    for(int i = 0; i < n;i++){
        bfs(i);
    }
    cout << ans << endl;
    return 0;
}
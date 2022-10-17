#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int MAXN = 1010;
const int INF = 0x7f7f7f7f;

int N, M;
vector<int> adj[MAXN];
int which[MAXN];
int dist[MAXN][MAXN];
vector<int> comp[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    memset(dist, 0x7f, sizeof(dist));

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int id = 1;
    int ans = 0;

    for(int i=0; i<N; i++){
        if(which[i]) continue;
        which[i] = id;
        comp[id].push_back(i);

        for(int j=0; j<comp[id].size(); j++){
            int src = comp[id][j];
            queue<pair<int, int> > bfs;
            bfs.push({src, 0});        
            dist[src][src] = 0;

            while(!bfs.empty()){
                int loc = bfs.front().first;
                int far = bfs.front().second;
                bfs.pop();

                for(int nbr : adj[loc])
                    if(dist[src][nbr] == INF){
                        if(j==0){
                            which[nbr] = id;
                            comp[id].push_back(nbr);
                        }
                        dist[src][nbr] = far+1;
                        bfs.push({nbr, far+1});
                    }
            }
        }

        for(int a : comp[id]){
            for(int n : adj[a]){
                int d1 = dist[i][a];
                int d2 = dist[i][n];
                if(d1%2 == d2%2){ 
                    cout << -1 << endl; 
                    return 0;
                }
            }
        }

        int diam = 0;
        for(int a : comp[id])
           for(int b : comp[id])
              diam = max(diam, dist[a][b]);
        ans += diam; 
        id++;        
    }

    cout << ans << endl;
}
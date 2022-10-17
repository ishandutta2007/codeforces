#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 3005;
const int INF = 0x7f7f7f7f;

int N, M;
vector<int> adj[MAXN];
int dist[MAXN][MAXN];

int S1, T1, L1;
int S2, T2, L2;

void fill_dist(int root){
    memset(dist[root], 0x7f, sizeof(dist[root]));
    dist[root][root] = 0;

    queue<int> bfs;
    bfs.push(root);

    while(!bfs.empty()){
        int loc = bfs.front();
        bfs.pop();

        for(int nbr : adj[loc]){
            if(dist[root][loc]+1 >= dist[root][nbr]) continue;
            dist[root][nbr] = dist[root][loc]+1;
            bfs.push(nbr);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }    

    cin >> S1 >> T1 >> L1;
    cin >> S2 >> T2 >> L2;
    S1--, S2--, T1--, T2--;

    for(int r=0; r<N; r++)
        fill_dist(r);

    if(dist[S1][T1] > L1 || dist[S2][T2] > L2){
        cout << -1 << endl;
        return 0;
    }

    int ans = max(0, M - dist[S1][T1] - dist[S2][T2]);

    for(int a=0; a<N; a++)
        for(int b=0; b<N; b++){
            if(dist[S1][a] + dist[a][b] + dist[b][T1] > L1) continue;
            if(dist[S2][a] + dist[a][b] + dist[b][T2] > L2) continue;

            int eu = dist[S1][a] + dist[S2][a];
            eu += dist[a][b];
            eu += dist[b][T1] + dist[b][T2];
            ans = max(ans, M - eu);
        }

    swap(S1, T1);

    for(int a=0; a<N; a++)
        for(int b=0; b<N; b++){
            if(dist[S1][a] + dist[a][b] + dist[b][T1] > L1) continue;
            if(dist[S2][a] + dist[a][b] + dist[b][T2] > L2) continue;

            int eu = dist[S1][a] + dist[S2][a];
            eu += dist[a][b];
            eu += dist[b][T1] + dist[b][T2];
            ans = max(ans, M - eu);
        }


    cout << ans << endl;
}
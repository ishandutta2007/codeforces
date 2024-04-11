#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

int N, M;
vector<int> edge[MAXN];
int dist[MAXN][MAXN];

int S, T, L, S2, T2, L2;

int cdist[MAXN];
vector <int> q;

void bfs (int start)
{
    for (int i = 0; i < MAXN; i++)
        cdist[i] = 1e9;
    
    q.clear();
    q.push_back (start);
    cdist[start] = 0;
    
    for (int i = 0; i < q.size(); i++)
    {
        int cloc = q[i];
        for (int j = 0; j < edge[cloc].size(); j++)
        {
            int neigh = edge[cloc][j];
            
            if (cdist[neigh] > cdist[cloc] + 1)
            {
                cdist[neigh] = cdist[cloc] + 1;
                q.push_back (neigh);
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        dist[start][i] = cdist[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }
    
    for (int i = 0; i < N; i++)
        bfs (i);
    
    cin >> S >> T >> L >> S2 >> T2 >> L2;
    S--, T--, S2--, T2--;
    
    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }*/
    
    int res = 1e9;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (dist[S][i] + dist[i][j] + dist[j][T] <= L &&
                dist[S2][i] + dist[i][j] + dist[j][T2] <= L2)
            {
                res = min (res, dist[S][i] + dist[i][j] + dist[j][T] + dist[S2][i] + dist[j][T2]);
                //cout << " " << res << " " << i << " " << j << "\n";
            }
            
            swap (S2, T2);
            if (dist[S][i] + dist[i][j] + dist[j][T] <= L &&
                dist[S2][i] + dist[i][j] + dist[j][T2] <= L2)
            {
                res = min (res, dist[S][i] + dist[i][j] + dist[j][T] + dist[S2][i] + dist[j][T2]);
                //cout << res << " " << i << " " << j << "\n";

            }
        }
    if (dist[S][T] <= L && dist[S2][T2] <= L2)
    {
        res = min (res, dist[S][T] + dist[S2][T2]);
    }
    
    
    if (res <= M)
        cout << M - res << "\n";
    else
        cout << "-1\n";
    return 0;
}
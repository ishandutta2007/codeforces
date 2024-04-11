#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 44;
const int MAXN = 5e6;

int R, C;
char rect[2005][2005];
vector<int> dist(MAXN + 5, INF);
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        int row = u / C, col = u % C;
        for(auto d : dir)
        {
            int nrow = row + d.first, ncol = col + d.second;
            if(nrow < 0 || nrow >= R || ncol < 0 || ncol >= C)
                continue;
            if(rect[nrow][ncol] == '*')
                continue;
            int v = C*nrow + ncol;
            int wt = ((d.second == -1) ? 1 : 0);
            if(dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    int sr, sc;
    cin >> sr >> sc;
    sr--;
    sc--;
    int ml, mr;
    cin >> ml >> mr;

    for(int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++)
        {
            rect[i][j] = s[j];
        }
    }
    dijkstra(C*sr + sc);
    int ans = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            int diff = j - sc;
            int v = C*i + j;
            if(dist[v] <= ml && dist[v] + diff <= mr)
            {
                //cout << i << " " << j << " " << v << " " << diff << " " << dist[v] << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
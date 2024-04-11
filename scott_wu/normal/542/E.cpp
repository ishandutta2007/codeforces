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
const int MAXN = 1100;

int N, M;
vector <int> edge[MAXN];
bool seen[MAXN];
bool bad;
int par[MAXN];

vector <int> cvert;
int dist[MAXN];

void flood (int cloc, int cpar)
{
    if (par[cloc] == 1 - cpar)
    {
        bad = true;
        return;
    }
    
    if (seen[cloc])
        return;
    seen[cloc] = true;
    par[cloc] = cpar;
    cvert.push_back (cloc);
    
    for (int i = 0; i < edge[cloc].size(); i++)
        flood (edge[cloc][i], 1 - cpar);
}

vector <int> q;

int solve (int start)
{
    cvert.clear();
    flood (start, 0);
    
    int res = 0;
    for (int i = 0; i < cvert.size(); i++)
    {
        int cloc = cvert[i];
        
        for (int j = 0; j < N; j++)
            dist[j] = 1e9;
        
        dist[cloc] = 0;
        q.clear();
        q.push_back (cloc);
        
        for (int j = 0; j < q.size(); j++)
        {
            int x = q[j];
            for (int k = 0; k < edge[x].size(); k++)
            {
                int neigh = edge[x][k];
                if (dist[neigh] > dist[x] + 1)
                {
                    dist[neigh] = dist[x] + 1;
                    
                    //cout << i << " " << neigh << " " << dist[neigh] << "\n";
                    res = max (res, dist[neigh]);
                    q.push_back (neigh);
                }
            }
        }
    }
    
    //cout << start << " " << res << "\n";
    return res;
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
    {
        seen[i] = false;
        par[i] = 2;
    }
    bad = false;
    
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (!seen[i])
            ans += solve (i);
    
    if (bad)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}
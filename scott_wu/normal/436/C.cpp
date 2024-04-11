#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 12;
const int MAXK = 1010;
const int MAXT = 1001000;

int N, M, K, W;
char grid[MAXK][MAXN][MAXN];
int edge[MAXK][MAXK];

int ne;
pair <int, int> elist[MAXT];

int parent[MAXK];
vector <int> e[MAXK];

vector <pair <int, int> > ans;

int find (int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find (parent[x]);
}

void uni (int a, int b)
{
    a = find (a), b = find (b);
    parent[b] = a;
}

inline bool cmp (pair <int, int> left, pair <int, int> right)
{
    int a = edge[left.first][left.second];
    int b = edge[right.first][right.second];
    
    return a < b;
}

int res = 0;

void flood (int cloc, int last)
{
    if (last != -1)
    {
        res += edge[cloc][last];
        ans.push_back (make_pair (cloc, last));
    }
        
    for (int i = 0; i < e[cloc].size(); i++)
    {
        int neigh = e[cloc][i];
        if (neigh != last)
            flood (neigh, cloc);
    }
}

int main()
{
    cin >> N >> M >> K >> W;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                cin >> grid[i][j][k];
    
    for (int i = 0; i < K; i++)
    {
        int best = 1e9, bloc = -1;
        for (int j = 0; j < i; j++)
        {
            int score = N * M;
            
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                    if (grid[i][k][l] == grid[j][k][l])
                        score--;
            
            edge[i+1][j+1] = edge[j+1][i+1] = score * W;
        }
        edge[i+1][0] = edge[0][i+1] = N * M;
    }
    K++;
    
    for (int i = 0; i < K; i++)
    {
        parent[i] = i;
        for (int j = i + 1; j < K; j++)
            elist[ne++] = make_pair (i, j);
    }
    
    sort (elist, elist + ne, cmp);
    for (int i = 0; i < ne; i++)
    {
        int a = elist[i].first, b = elist[i].second;
        
        if (find (a) != find (b))
        {
            uni (a, b);
            e[a].push_back (b);
            e[b].push_back (a);
        }
    }
    
    flood (0, -1);
    
    cout << res << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    
    //system ("Pause");
    return 0;
}
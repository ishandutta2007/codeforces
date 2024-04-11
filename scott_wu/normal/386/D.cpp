#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define f first.first
#define g first.second
#define h second
typedef long long ll;
const int MAXN = 72;

int N;
int start[3];
char edge[MAXN][MAXN];

int dist[MAXN][MAXN][MAXN];
pair <int, int> last[MAXN][MAXN][MAXN];

pair <int, int> ans[1000000];

vector <pair <pair <int, int>, int> > q;

pair <pair <int, int>, int> s3 (int a, int b, int c)
{
    int x[3] = {a, b, c};
    sort (x, x + 3);
    return make_pair (make_pair (x[0], x[1]), x[2]);
}

void bfs()
{
    dist[start[0]][start[1]][start[2]] = 0;
    q.push_back (make_pair (make_pair (start[0], start[1]), start[2]));
    
    pair <pair <int, int>, int> temp;
    for (int nq = 0; nq < q.size(); nq++)
    {
        int a = q[nq].first.first, b = q[nq].first.second, c = q[nq].second;
        
        for (int i = 0; i < N; i++)
        {
            if (i == a || i == b || i == c)
                continue;
            
            if (edge[b][c] == edge[a][i])
            {
                temp = s3 (i, b, c);
                if (dist[temp.f][temp.g][temp.h] == 1000000)
                {
                    dist[temp.f][temp.g][temp.h] = dist[a][b][c] + 1;
                    last[temp.f][temp.g][temp.h] = make_pair (a, i);
                    
                    q.push_back (make_pair (make_pair (temp.f, temp.g), temp.h));
                }
            }
            if (edge[a][c] == edge[b][i])
            {
                temp = s3 (i, a, c);
                if (dist[temp.f][temp.g][temp.h] == 1000000)
                {
                    dist[temp.f][temp.g][temp.h] = dist[a][b][c] + 1;
                    last[temp.f][temp.g][temp.h] = make_pair (b, i);
                    
                    q.push_back (make_pair (make_pair (temp.f, temp.g), temp.h));
                }
            }
            if (edge[a][b] == edge[c][i])
            {
                temp = s3 (i, b, a);
                if (dist[temp.f][temp.g][temp.h] == 1000000)
                {
                    dist[temp.f][temp.g][temp.h] = dist[a][b][c] + 1;
                    last[temp.f][temp.g][temp.h] = make_pair (c, i);
                    
                    q.push_back (make_pair (make_pair (temp.f, temp.g), temp.h));
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dist[i][j][k] = 1000000;
                
    cin >> N;
    for (int i = 0; i < 3; i++)
    {
        cin >> start[i];
        start[i]--;
    }
    sort (start, start + 3);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> edge[i][j];
    
    bfs();
    
    if (dist[0][1][2] == 1000000)
    {
        cout << "-1\n";
        return 0;
    }
    
    cout << dist[0][1][2] << "\n";
    int res[3] = {0, 1, 2};
    
    for (int i = 0; i < dist[0][1][2]; i++)
    {
        pair <int, int> x = last[res[0]][res[1]][res[2]];
        
        ans[dist[0][1][2]-1-i] = make_pair (x.first + 1, x.second + 1);
        
        pair <pair <int, int>, int> temp;
        if (res[0] == x.second)
            temp = s3 (x.first, res[1], res[2]);
        else if (res[1] == x.second)
            temp = s3 (x.first, res[0], res[2]);
        else
            temp = s3 (x.first, res[0], res[1]);
        
        res[0] = temp.f;
        res[1] = temp.g;
        res[2] = temp.h;
    }
    for (int i = 0; i < dist[0][1][2]; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}
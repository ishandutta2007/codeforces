#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 310;

int N, M;
string init[MAXN][MAXN], goal[MAXN][MAXN];
vector <char> g[MAXN][MAXN];
int gs[MAXN][MAXN];

vector <pair <int, int> > moves;
vector <int> ans;

void move (int x, int y, int x2, int y2)
{
    if (gs[x][y] == g[x][y].size())
        return;
    int gstart = gs[x][y];
    char f = g[x][y][gstart];
    gs[x][y]++;
    g[x2][y2].push_back(f);
    moves.push_back(make_pair(x * MAXN + y, x2 * MAXN + y2));
}

void do_it()
{
    // put stuff down then reverse
    while (gs[0][0] < g[0][0].size())
    {
        move (0, 0, N - 1, 0);
    }
    while (gs[N-1][M-1] < g[N-1][M-1].size())
    {
        move (N - 1, M - 1, N - 1, 0);
    }
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (i == 0 && j == 0) continue;
                if (i == N - 1 && j == M - 1) continue;
                while (gs[i][j] < g[i][j].size())
                {
                    char nf = g[i][j][gs[i][j]];
                    if (nf == '0')
                    {
                        if (i > 0)
                            move (i, j, 0, j);
                        else if (j > 0)
                            move (i, j, i, 0);
                    }
                    else
                    {
                        if (i < N - 1)
                            move (i, j, N - 1, j);
                        else if (j < M - 1)
                            move (i, j, i, M - 1);
                    }
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> init[i][j];

            gs[i][j] = 0;
            for (int k = init[i][j].length() - 1; k >= 0; k--)
                g[i][j].push_back(init[i][j][k]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> goal[i][j];
        }
    }

    do_it();

    for (int i = 0; i < moves.size(); i++)
    {
        int nl = moves[i].first, nr = moves[i].second;
        ans.push_back (nl / MAXN);
        ans.push_back (nl % MAXN);
        ans.push_back (nr / MAXN);
        ans.push_back (nr % MAXN);
    }

    moves.clear();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            g[i][j].clear();
            gs[i][j] = 0;
            for (int k = 0; k < goal[i][j].length(); k++)
                g[i][j].push_back(goal[i][j][k]);
        }
    }

    do_it();
    for (int i = (int) moves.size() - 1; i >= 0; i--)
    {
        int nl = moves[i].first, nr = moves[i].second;
        ans.push_back (nr / MAXN);
        ans.push_back (nr % MAXN);
        ans.push_back (nl / MAXN);
        ans.push_back (nl % MAXN);        
    }

    printf("%d\n", (int) ans.size() / 4);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i % 4 == 3)
            printf("%d\n", ans[i] + 1);
        else
            printf("%d ", ans[i] + 1);
    }
}
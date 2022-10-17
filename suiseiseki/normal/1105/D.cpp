#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
struct Node
{
    int _x;
    int _y;
    Node(int x,int y):_x(x),_y(y){}
};
int Next[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int next_time[10];
int Map[MAXN][MAXN];
int number[10];
int speed[10];
int vis[10];
queue<Node> player[10];
 
int main()
{
    int n, m, p;
    char c;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= p; i++)
    {
        scanf("%d", &speed[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '.')
                Map[i][j] = 0;
            else if (c == '#')
                Map[i][j] = -1;
            else
            {
                Map[i][j] = c - '0';
                player[c - '0'].push(Node(i, j));
                number[c - '0']++;
                next_time[c - '0']++;
            }
        }
    }
    int flag = p;
    while (flag > 0)
    {
        for (int i = 1; i <= p; i++)
        {
            if (player[i].empty())
                continue;
            for (int times = 1; times <= speed[i]; times++)
            {
                int ti = next_time[i];
                next_time[i] = 0;
                for (int z = 1; z <= ti; z++)
                {
                    //cout << 2 << endl;
                    int x = player[i].front()._x;
                    int y = player[i].front()._y;
                    player[i].pop();
                    for (int j = 0; j < 4; j++)
                    {
                        int tx = x + Next[j][0];
                        int ty = y + Next[j][1];
                        if (tx < 1 || tx > n || ty < 1 || ty > m)
                            continue;
                        if (Map[tx][ty] != 0 || Map[tx][ty] == '#')
                            continue;
                        Map[tx][ty] = i;
                        number[i]++;
                        player[i].push(Node(tx, ty));
                        next_time[i]++;
                    }
                }
                if (player[i].empty()&&vis[i] == 0)
                {
                    flag--;
                    vis[i] = 1;
                    break;
                }
                /*
                for (int v = 1;v<=n;v++)
                {
                    for (int c = 1;c<=m;c++)
                        cout << Map[v][c] << ' ';
                    cout << endl;
                }
                */
            }
            //cout << 3 << endl;
            //cout << player[i].size() << endl;
        }
        if (flag <= 0)
            break;
        //cout << 4 << endl;
    }
 
    for (int i = 1; i <= p; i++)
        printf("%d ", number[i]);
    printf("\n");
 
    return 0;
}
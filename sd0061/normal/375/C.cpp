#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
const int N = 25;
int n , m , v[N];
char g[N][N];
int d[N][N][1 << 8];
int P , cnt , sx , sy;
pair<int , int> pos[N];
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};

struct opt
{
    int x , y , mask;
    opt (int _x , int _y , int _mask)
    {
        x = _x , y = _y , mask = _mask;
    }
};

void work()
{
    int i , j , k , x , y , q , w;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (isdigit(g[i][j]))
            {
                -- g[i][j] , ++ P , ++ cnt;
                pos[g[i][j] - '0'] = make_pair(i , j);
            }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (g[i][j] == 'B')
                pos[P ++] = make_pair(i , j);
            else if (g[i][j] == 'S')
                sx = i , sy = j , g[i][j] = '.';
    for (i = 0 ; i < cnt ; ++ i)
        scanf("%d" , &v[i]);
    queue<opt> Q;
    memset(d , -1 , sizeof(d));
    Q.push(opt(sx , sy , 0));
    d[sx][sy][0] = 0;
    while (!Q.empty())
    {
        i = Q.front().x , j = Q.front().y , q = Q.front().mask , Q.pop();
        for (k = 0 ; k < 4 ; ++ k)
        {
            x = i + dx[k] , y = j + dy[k];
            if (x > 0 && x <= n && y > 0 && y <= m && g[x][y] == '.')
            {
                w = q;
                for (int l = 0 ; l < P ; ++ l)
                    if (x > pos[l].first && (j == pos[l].second && y == pos[l].second - 1 || y == pos[l].second && j == pos[l].second - 1))
                        w ^= 1 << l;
                if (!~d[x][y][w])
                    d[x][y][w] = d[i][j][q] + 1 , Q.push(opt(x , y , w));
            }
        }
    }
    int ans = 0;
    for (i = 0 ; i < 1 << cnt ; ++ i)
    {
        int sum = -d[sx][sy][i];
        if (sum == 1) continue;
        for (j = 0 ; j < cnt ; ++ j)
            if (i & (1 << j))
                sum += v[j];
        ans = max(ans , sum);
    }
    printf("%d\n" , ans);
}

int main()
{
//    freopen("1.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
//    while (scanf("%d%d",&n,&k) , n || k)
        work();
    return 0;
}
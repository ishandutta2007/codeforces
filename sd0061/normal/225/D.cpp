#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <set>
using namespace std;
#define N 20
int n , m;
char s[N][N];
int dx[] = {0 , 0 , -1 , 1} , dy[] = {-1 , 1 , 0 , 0};
int f[N][N][65536] , sx , sy , ex , ey;
struct opt
{
    int x , y , d;
    opt () {x = y = d = 0;}
    opt (int _x , int _y , int _d)
    {
        x = _x , y = _y , d = _d;
    }
};
queue<opt> Q;
void work()
{
    int i , j , mask , w , len = 0 , x , y , X , Y , d , p;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 0 ; i <= n ; ++ i) s[i][0] = s[i][m + 1] = '#';
    for (i = 0 ; i <= m ; ++ i) s[0][i] = s[n + 1][i] = '#';
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            if (isdigit(s[i][j]))
                len = max(len , s[i][j] - '0');
            if (s[i][j] == '1')
                sx = i , sy = j;
            if (s[i][j] == '@')
                ex = i , ey = j;
        }
    d = 0 , x = sx , y = sy , mask = (1 << len + len - 2) - 1;
    for (i = 0 ; i + 1 < len ; ++ i)
    {
        for (j = 0 ; j < 4 ; ++ j)
        {
            X = x + dx[j] , Y = y + dy[j];
            if (s[X][Y] == s[x][y] + 1)
                break;
        }
        d |= j << i + i;
        x = X , y = Y;
    }
    memset(f , -1 , sizeof(f));
    f[sx][sy][d] = 0;
    Q.push(opt(sx , sy , d));

    while (!Q.empty())
    {
        x = Q.front().x , y = Q.front().y , d = Q.front().d , Q.pop();
        X = x , Y = y , w = f[x][y][d];
        if (x == ex && y == ey)
        {
            printf("%d\n" , w);
            return;
        }
        set< pair<int , int> > body;
        for (i = 0 ; i < len - 2 ; ++ i)
        {
            j = d >> i + i & 3;
            X += dx[j] , Y += dy[j];
            body.insert(make_pair(X , Y));
        }
        for (i = 0 ; i < 4 ; ++ i)
        {
            X = x + dx[i] , Y = y + dy[i];
            if (s[X][Y] != '#' && !body.count(make_pair(X , Y)))
            {
                p = (d << 2 & mask) | (i ^ 1);
                if (!~f[X][Y][p])
                    f[X][Y][p] = w + 1 , Q.push(opt(X , Y , p));
            }
        }
    }
    puts("-1");
}

int main()
{
    work();
    return 0;
}
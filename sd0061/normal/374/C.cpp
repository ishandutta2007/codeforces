#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1005;

int n , m;
char s[N][N];
int f[N][N] , d[N][N];
queue< pair<int , int> > Q;
int dx[] = {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};
void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s", s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            for (int k = 0 ; k < 4 ; ++ k)
            {
                x = i + dx[k] , y = j + dy[k];
                if (x > 0 && x <= n && y > 0 && y <= m)
                    if (s[i][j] == 'D' && s[x][y] == 'I' || s[i][j] == 'I' && s[x][y] == 'M' || s[i][j] == 'M' && s[x][y] == 'A' || s[i][j] == 'A' && s[x][y] == 'D' )
                        ++ d[x][y];
            }
        }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (!d[i][j])
                Q.push(make_pair(i , j)) , f[i][j] = 1;
    int ans = 0 , tot = 0;
    while (!Q.empty())
    {
        i = Q.front().first , j = Q.front().second , Q.pop();
        for (int k = 0 ; k < 4 ; ++ k)
        {
            x = i + dx[k] , y = j + dy[k];
            if (x > 0 && x <= n && y > 0 && y <= m)
                if (s[i][j] == 'D' && s[x][y] == 'I' || s[i][j] == 'I' && s[x][y] == 'M' || s[i][j] == 'M' && s[x][y] == 'A' || s[i][j] == 'A' && s[x][y] == 'D' )
                {
                    f[x][y] = max(f[x][y] , f[i][j] + 1);
                    if (!-- d[x][y])
                        Q.push(make_pair(x , y));
                }
        }
        if (s[i][j] == 'A')
            ans = max(ans , f[i][j]) ;
        ++ tot;
    }
    ans >>= 2;
    if (tot != n * m)
        puts("Poor Inna!");
    else if (!ans)
        puts("Poor Dima!");
    else
        cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&u))
        work();
    return 0;
}
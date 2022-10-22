#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1005
int n , m;
char s[N][N];
int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};

void work()
{
    int i , j , x , y , k , z;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    for (i = 0 ; i < n ; ++ i)
    {
        for (j = 0 ; j < m ; ++ j)
            if (s[i][j] == '.')
            {
                for (k = 0 ; k < 4 ; ++ k)
                {
                    x = i + dx[k] , y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if (s[x][y] == '.') break;
                }
                if (k < 4)
                {
                    z = (i % 3) * 3 + j % 3;
                    s[i][j] = s[x][y] = '0' + z;
                    continue;
                }
                for (k = 0 ; k < 4 ; ++ k)
                {
                    x = i + dx[k] , y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if (s[x][y] != '#') break;
                }
                if (k < 4)
                    s[i][j] = s[x][y];
                else
                    break;
            }
        if (j < m) break;
    }
    if (i < n)
        puts("-1");
    else
        for (i = 0 ; i < n ; ++ i)
            puts(s[i]);
}

int main()
{
    work();
    return 0;
}
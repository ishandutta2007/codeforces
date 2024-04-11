#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n , m , K , s;
int f[10][4][2];
bool p[10][10];

void work()
{
    int i , j , k , x , y;
    cin >> n >> m >> K >> s;
    for (i = 1 ; i <= K ; ++ i)
        for (j = 0 ; j < 4 ; ++ j)
            f[i][j][0] = 1 << 30 , f[i][j][1] = -1 << 30;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            cin >> x;
            f[x][0][0] = min(f[x][0][0] , i + j);
            f[x][0][1] = max(f[x][0][1] , i + j);
            f[x][1][0] = min(f[x][1][0] , i - j);
            f[x][1][1] = max(f[x][1][1] , i - j);
            f[x][2][0] = min(f[x][2][0] , -i + j);
            f[x][2][1] = max(f[x][2][1] , -i + j);
            f[x][3][0] = min(f[x][3][0] , -i - j);
            f[x][3][1] = max(f[x][3][1] , -i - j);
        }
    for (i = 1 ; i <= s ; ++ i)
    {
        y = x ; cin >> x;
        if (i > 1) p[x][y] = p[y][x] = 1;
    }
    int ans = 0;
    for (i = 1 ; i <= K ; ++ i)
        for (j = 1 ; j <= K ; ++ j) if (p[i][j])
        {
            for (k = 0 ; k < 4 ; ++ k)
                ans = max(ans , f[i][k][1] - f[j][k][0]) ,
                ans = max(ans , f[j][k][1] - f[i][k][0]) ;
        }
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}
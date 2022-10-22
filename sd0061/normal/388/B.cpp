#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 2005
int n , K;
int cnt = 2 , p[N] , l[N] , w[N];
bool g[N][N];

void con(int x , int y)
{
    g[x][y] = g[y][x] = 1;
}

void work()
{
    int i , j , k , x = 1 , y , r , z;
    scanf("%d",&K) , r = K;
    k = 1 , i = 0;
    while (K > 1)
    {
        k += 3;
        con(x , cnt + 4);
        con(cnt + 4 , cnt + 1) , con(cnt + 4 , cnt + 2);
        con(cnt + 3 , cnt + 1) , con(cnt + 3 , cnt + 2);
        cnt += 4 , y = cnt - 1;
        l[i] = k , w[i] = y;
        x = y , K >>= 1 , ++ i;
    }
    con(x , 2);
    int e = i; z = 2;
    for (-- i ; i >= 0 ; -- i)
        if (r >> i & 1)
        {
            k = l[e - i - 1] , y = w[e - i - 1];
            p[k] = y;
            for (j = z ; j <= k - 1 ; ++ j)
                p[j] = ++ cnt;
            p[1] = 1;
            for (j = 2 ; j <= k ; ++ j)
                con(p[j] , p[j - 1]);
            z = k;
        }
    printf("%d\n" , cnt);
    for (i = 1 ; i <= cnt ; ++ i)
    {
        for (j = 1 ; j <= cnt ; ++ j)
            printf("%c" , g[i][j] ? 'Y' : 'N');
        puts("");
        //for (j = i+1 ; j <= cnt ; ++ j)if (g[i][j]) cerr <<i << ' ' << j<<endl;
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
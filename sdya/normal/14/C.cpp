#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int x[5][5], y[5][5];

bool check(int a, int b, int c, int d, int x, int y, int z, int t)
{
    if (a == x && b == y && c == z && d == t) return true;
    if (c == x && d == y && a == z && b == t) return true;
    return false;
}

bool check_r(int x1, int y1, int x2, int y2)
{
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if ((x2 - x1) == 0 || (y2 - y1) == 0) return false;
    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= 4; j ++)
            for (int k = 1; k <= 4; k ++)
                for (int l = 1; l <= 4; l ++)
                    if (i != j && i != k && i != l && j != k && j != l && k != l)
                    {
                        if (check(x[i][1],y[i][1],x[i][2],y[i][2],x1,y1,x1,y2) && 
                            check(x[j][1],y[j][1],x[j][2],y[j][2],x1,y1,x2,y1) && 
                            check(x[k][1],y[k][1],x[k][2],y[k][2],x2,y2,x1,y2) && 
                            check(x[l][1],y[l][1],x[l][2],y[l][2],x2,y2,x2,y1)) return true;
                    }
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 1; i <= 4; i ++)
        scanf("%d%d%d%d", &x[i][1], &y[i][1], &x[i][2], &y[i][2]);

    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= 4; j ++)
            for (int k = 1; k <= 2; k ++)
                for (int l = 1; l <= 2; l ++)
                    if (check_r(x[i][k],y[i][k],x[j][l],y[j][l]))
                    {
                        printf("YES\n");
                        return 0;
                    }
    printf("NO\n");
    return 0;
}
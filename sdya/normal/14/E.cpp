#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long d[25][15][15][6][6];
int n, t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= 4; j ++)
            if (i != j) d[2][0][0][i][j] = 1;

    for (int i = 3; i <= n; i ++)
        for (int k = 0; k <= t; k ++)
            for (int l = 0; l <= t - 1; l ++)
                for (int p = 1; p <= 4; p ++)
                    for (int q = 1; q <= 4; q ++)
                        for (int r = 1; r <= 4; r ++)
                            if (p != q && r != p)
                            {
                                if (r < p && p > q)
                                {
                                    if (k > 0) d[i][k][l][p][q] += d[i - 1][k - 1][l][r][p];
                                } else
                                if (r > p && p < q)
                                {
                                    if (l > 0) d[i][k][l][p][q] += d[i - 1][k][l - 1][r][p];
                                } else
                                d[i][k][l][p][q] += d[i - 1][k][l][r][p];
                            }


    long long res = 0;
    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= 4; j ++)
            res += d[n][t][t - 1][i][j];
    cout << res << endl;

    return 0;
}
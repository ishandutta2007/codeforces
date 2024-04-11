#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, m;
char s[600][600];
int a[600][600], b[600][600];
int d[600][26][26];

int f[2], t;

#define min(a, b) (a < b ? a : b)

void print(int s, int u, int v)
{
    if (s == 0)
    {
        f[0] = u, f[1] = v;
        for (int k = 0; k < m; k ++)
            b[s][k] = f[k % 2];
        return;
    }

    f[0] = u, f[1] = v;
    int cur = 0;
    for (int l = 0; l < m; l ++)
         if (a[s][l] != f[l % 2]) cur ++;

    for (int l = 0; l < 26; l ++)
        for (int r = 0; r < 26; r ++)
            if (l != r && l != u && r != v)
                if (d[s][u][v] == d[s - 1][l][r] + cur)
                {
                    for (int k = 0; k < m; k ++)
                        b[s][k] = f[k % 2];
                    print(s - 1, l, r);
                    return;
                }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i ++)
        gets(s[i]);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            a[i][j] = s[i][j] - 'a';
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            if (i != j)
            {
                f[0] = i, f[1] = j;
                for (int k = 0; k < m; k ++)
                    if (a[0][k] != f[k % 2]) d[0][i][j] ++;
            }

    for (int i = 1; i < n; i ++)
        for (int j = 0; j < 26; j ++)
            for (int k = 0; k < 26; k ++)
                if (j != k)
            {
                f[0] = j, f[1] = k;
                int cur = 0;
                for (int l = 0; l < m; l ++)
                    if (a[i][l] != f[l % 2]) cur ++;

                d[i][j][k] = 1000000000;

                for (int l = 0; l < 26; l ++)
                    for (int r = 0; r < 26; r ++)
                        if (l != r && l != j && r != k)
                            d[i][j][k] = min(d[i][j][k], d[i - 1][l][r] + cur);
            }

    int best = 1000000000, u = -1, v = -1;
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            if (d[n - 1][i][j] < best && i != j) best = d[n - 1][i][j], u = i, v = j;

    printf("%d\n", best);
    print(n - 1, u, v);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
            printf("%c", (char)(b[i][j] + 'a'));
        printf("\n");
    }
    return 0;
}
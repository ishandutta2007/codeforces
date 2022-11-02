#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
char s[60][60];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i ++)
        gets(s[i]);

    int lx = 100, ly = 100, rx = -1, ry = -1;

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (s[i][j] == '*')
            {
                if (i < lx) lx = i;
                if (i > rx) rx = i;
                if (j < ly) ly = j;
                if (j > ry) ry = j;
            }
    for (int i = lx; i <= rx; i ++)
    {
        for (int j = ly; j <= ry; j ++)
            printf("%c", s[i][j]);
        printf("\n");
    }
    return 0;
}
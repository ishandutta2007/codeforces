#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>

int a1, b1, c1;
int a2, b2, c2;

int d, d1, d2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d", &a1, &b1, &c1);
    scanf("%d%d%d", &a2, &b2, &c2);

    if (a1 == 0 && b1 == 0 && c1 != 0)
    {
        printf("0\n");
        return 0;
    }
    if (a2 == 0 && b2 == 0 && c2 != 0)
    {
        printf("0\n");
        return 0;
    }

    c1 = -c1;
    c2 = -c2;

    d = a1 * b2 - a2 * b1;
    d1 = c1 * b2 - c2 * b1;
    d2 = a1 * c2 - a2 * c1;

    if (d != 0)
    {
        printf("1\n");
        return 0;
    }

    if (d == 0)
    {
        if (d1 != 0 || d2 != 0)
        {
            printf("0\n");
            return 0;
        } else
        {
            printf("-1\n");
            return 0;
        }
    }

    return 0;
}
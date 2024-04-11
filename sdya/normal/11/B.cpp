#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int x;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &x);
    if (x < 0) x = -x;
    if (x == 0)
    {
        printf("0\n");
        return 0;
    }

    int cur = 0, t = 1;
    for (int i = 1; i <= 100000; i ++)
    {
        cur += t;
        if (cur == x)
        {
            printf("%d\n", i);
            return 0;
        }

        if (cur > x && (cur - x) % 2 == 0)
        {
            printf("%d\n", i);
            return 0;
        }
        t ++;
    }

    return 0;
}
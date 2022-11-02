#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int x[4], y[4];

bool check()
{
    int c = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
    int b = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
    int a = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);

    if (a == b + c || b == a + c || c == a + b)
        return true;
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 1; i <= 3; i ++)
        scanf("%d%d", &x[i], &y[i]);

    int c = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
    int b = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
    int a = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);

    if (check()) printf("RIGHT\n"); else
    {
        for (int i = 1; i <= 3; i ++)
            for (int j = -1; j <= 1; j ++)
                for (int k = -1; k <= 1; k ++)
                    if (abs(j) + abs(k) == 1)
                    {
                        x[i] += j, y[i] += k;
                        bool good = true;
                        for (int l = 1; l <= 3; l ++)
                            if (x[i] == x[l] && y[i] == y[l] && i != l)
                                good = false;
                        if (good)
                        {
                            if (check())
                            {
                                printf("ALMOST\n");
                                return 0;
                            }
                        }
                        x[i] -= j, y[i] -= k;
                    }
        printf("NEITHER\n");
    }
    
    return 0;
}
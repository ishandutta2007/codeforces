#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool p[2000];

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i ++)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= 2000; i ++)
        p[i] = is_prime(i);

    int res = 0;
    for (int i = 2; i <= n; i ++)
        if (p[i])
    {
        for (int j = 1; j <= 1100; j ++)
            if (p[j])
            {
                int k = j + 1;
                for (int l = j + 1; l <= 1100; l ++)
                    if (p[l])
                    {
                        k = l;
                        break;
                    }
                if (i == j + k + 1)
                {
                    res ++;
                    break;
                }
            }
    }

    if (res >= k)
        printf("YES\n"); else
        printf("NO\n");
    return 0;
}
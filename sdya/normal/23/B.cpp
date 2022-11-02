#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
    {
        int n;
        scanf("%d", &n);
        if (n < 3) printf("0\n"); else
            printf("%d\n", n - 2);
    }
    return 0;
}
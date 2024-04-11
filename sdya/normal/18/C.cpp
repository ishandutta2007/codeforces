#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
int a[200000];
int s1[200000], s2[200000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), s1[i] = s1[i - 1] + a[i];

    for (int i = n; i >= 1; i --)
        s2[i] = s2[i + 1] + a[i];

    int res = 0;
    for (int i = 1; i < n; i ++)
        if (s1[i] == s2[i + 1])
            res ++;
    printf("%d\n", res);
    return 0;
}
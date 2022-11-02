#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int a[300000], b[300000];
int n, num[300000], used[300000];

bool comp(int p, int q)
{
    if (a[p] < a[q]) return true;
    if (a[p] > a[q]) return false;
    return (b[p] < b[q]);
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i ++)
        scanf("%d%d", &a[i], &b[i]), num[i] = i, used[i] = false;
    sort(num + 1, num + 2 * n, comp);
    if (n == 1)
    {
        printf("YES\n1\n");
        return;
    }
    printf("YES\n");
    for (int i = 1; i <= 2 * n - 2; i ++)
        if (b[num[i]] <= b[num[i + 1]])
        {
            used[i] = used[i + 1] = true;
            printf("%d ", num[i + 1]);
            i ++;
        }

    int s = 0;
    for (int i = 1; i <= 2 * n - 1; i ++)
        if (!used[i])
        {
            s ++;
            if (s % 2 == 1)
                printf("%d ", num[i]);
        }
    printf("\n");
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
        solve();
    return 0;
}
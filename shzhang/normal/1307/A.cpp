#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int a[105];

void work(void)
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int cur = 2;
    while (d > 0 && cur <= n) {
        while (cur <= n && !a[cur]) cur++;
        if (cur > n) break;
        if (d < cur - 1) break;
        a[1]++; d -= cur - 1; a[cur]--;
    }
    printf("%d\n", a[1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}
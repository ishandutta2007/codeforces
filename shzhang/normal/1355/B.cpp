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
#include <utility>

using namespace std;

#define ll long long

int t, a[200005], n;

int f[200005], Fmax[200005];

void work(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        //printf("%d ", a[i]);
        if (a[i] > i) {
            f[i] = -1;
        } else {
            f[i] = Fmax[i - a[i]] + 1;
        }
        Fmax[i] = max(Fmax[i-1], f[i]);
    }
    printf("%d\n", Fmax[n]);
    for (int i = 0; i <= n; i++) {
        a[i] = f[i] = Fmax[i] = 0;
    }
}

int main()
{
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        work();
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int a[105];
bool colored[105];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int remaining = n; int ans = 0;
    while (remaining) {
        int minval = 1000000;
        for (int i = 1; i <= n; i++) {
            if (!colored[i]) minval = min(minval, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] % minval == 0 && !colored[i]) colored[i] = true, remaining--;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}
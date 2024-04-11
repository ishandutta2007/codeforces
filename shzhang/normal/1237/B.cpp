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

int a[100005];
int tim[100005];
int b[100005];
bool used[100005];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        tim[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        b[i] = tim[b[i]];
        //printf("%d ", b[i]);
    }
    int minfull = 0; int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (minfull < b[i] - 1) ans++;
        used[b[i]] = true;
        while (used[minfull+1]) minfull++;
    }
    printf("%d", ans);
    return 0;
}
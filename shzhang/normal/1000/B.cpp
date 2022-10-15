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

int n, M;
int a[100005];

int main()
{
    scanf("%d%d", &n, &M);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    a[n+1] = M; n++;
    int ans = 0;
    int baseans;
    for (int i = 1; i <= n; i += 2) ans += a[i] - a[i-1];
    baseans = ans;
    int on_time = 0; int off_time = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (i % 2 == 0) {
            on_time += a[i+1] - a[i];
        } else {
            off_time += a[i+1] - a[i];
        }
        if (a[i] - 1 != a[i-1]) {
            ans = max(ans, baseans - on_time + off_time + (i % 2 ? -1 : 1));
        }
        if (a[i] + 1 != a[i+1]) {
            ans = max(ans, baseans - on_time + off_time + (i % 2 ? -1 : 1));
        }
    }
    printf("%d", ans);
    return 0;
}
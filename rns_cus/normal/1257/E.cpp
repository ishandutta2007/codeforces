#include <bits/stdc++.h>
using namespace std;

#define N 200100

int x, y, z, a[N], b[N], c[N], p[N], q[N];

int main() {
    scanf("%d %d %d", &x, &y, &z);
    for (int i = 1; i <= x; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= y; i ++) scanf("%d", &b[i]);
    for (int i = 1; i <= z; i ++) scanf("%d", &c[i]);
    int ans = x + z;
    sort(a + 1, a + x + 1);
    sort(c + 1, c + z + 1);
    for (int i = 1; i <= x; i ++) p[i] = a[i] - 2 * i - (lower_bound(c + 1, c + z + 1, a[i]) - c - 1);
    for (int i = 1; i <= z; i ++) q[i] = x + y + z + 1 - c[i] - 2 * (z + 1 - i) - (a + x + 1 - lower_bound(a + 1, a + x + 1, c[i]));

//    for (int i = 1; i <= x; i ++) cout << p[i] << ' '; cout << endl;
//    for (int i = 1; i <= z; i ++) cout << q[i] << ' '; cout << endl;

    p[0] = q[z+1] = 0;
    for (int i = z; i; i --) q[i] = min(q[i], q[i+1]);
    int mn = 0;
    for (int i = 0; i <= x; i ++) mn = min(mn, p[i] + q[lower_bound(c + 1, c + z + 1, a[i]) - c]);
    printf("%d\n", ans + mn);

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;

int m, n, k, t;
int a[N], l[N], r[N], d[N];

bool cmp(int x, int y) { 
    return x > y;
}
int get(int v) {
    //printf("get %d\n", v);
    int f[N] = {0};
    for (int i = 1; i <= k; i ++) {
        if (d[i] > v) {
            f[ l[i] ] = max(r[i], f[ l[i] ]);
        }
    }
    int pos = 0, ans = 0;
    while (1) {
        //printf("pos 1 = %d\n", pos);
        while (pos <= n && f[pos + 1] == 0) {
            pos ++; ans ++; 
        }
        //printf("pos 2 = %d\n", pos);

        if (pos == n + 1) break;
        int mx = 0;
        for (int i = pos + 1; i <= n; i ++) {
            mx = max(mx, f[i]);
            if (i == mx || i == n) {
                ans = ans + 3 * (i - pos);
                pos = i; break; 
            }
        } 
        //printf("pos 3 = %d, ans = %d\n", pos, ans);
    }
    //printf("ans = %d\n", ans);
    return ans;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= k; i ++) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    sort(a + 1, a + 1 + m, cmp);
    int lef = 0, rig = m + 1;
    while (rig - lef > 1) {
        int mid = (lef + rig) >> 1;
        if (get(a[mid]) <= t) {
            lef = mid;
        } else {
            rig = mid;
        }
    }
    printf("%d\n", lef);
}
#include <bits/stdc++.h>
using namespace std;
 
#define N 300300
 
int n, x[N], y[N];
 
int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]);
    int mx = -1e9, mn = 1e9, rlt = 0; vector <int> vec;
    for (int i = 0; i < n; i ++) mx = max(mx, x[i]), mn = min(mn, x[i]);
    rlt += 2 * (mx - mn);
    for (int i = 0; i < n; i ++) if (x[i] == mn || x[i] == mx) vec.push_back(i);
    mx = -1e9, mn = 1e9;
    for (int i = 0; i < n; i ++) mx = max(mx, y[i]), mn = min(mn, y[i]);
    rlt += 2 * (mx - mn);
    for (int i = 0; i < n; i ++) if (y[i] == mn || y[i] == mx) vec.push_back(i);
    int sz = vec.size(), ans = 0;
    for (int i = 0; i < sz; i ++)
        for (int j = 0; j <= i; j ++)
            for (int k = 0; k < n; k ++)
                ans = max(ans, dist(vec[i], vec[j]) + dist(vec[j], k) + dist(k, vec[i]));
    printf("%d", ans);
    for (int i = 3; i < n; i ++) printf(" %d", rlt); puts("");
}
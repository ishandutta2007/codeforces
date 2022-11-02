#include<bits/stdc++.h>
using namespace std;

int n, a[100010], b[100010];

int dist(int x, int y, int xx, int yy) {
    int d[4] = {x, y, xx, yy};
    sort(d, d + 4);
    bool flag = 0;
    if(max(x, y) <= min(xx, yy) || max(xx, yy) <= min(x, y)) flag = 1;
    if(flag) return d[3] - d[0] + d[2] - d[1];
    else return d[3] - d[0] + d[1] - d[2];
}

int main() {
    int x = 1, y = 1;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i ++) {
        int c;
        scanf("%d", &c);
        if(a[c]) b[c] = i;
        else a[c] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        int xx = a[i], yy = b[i];
        ans += dist(x, y, xx, yy);
        x = xx, y = yy;
    }
    printf("%I64d\n", ans);
}
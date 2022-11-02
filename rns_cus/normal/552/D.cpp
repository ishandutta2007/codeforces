#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define N 2020
#define ep 1e-7

struct pnt {
    int x, y;
    pnt(int x = 0, int y = 0) : x(x), y(y) {}
    pnt operator -(pnt a) { return pnt(x - a.x, y - a.y); }
    pnt operator +(pnt a) { return pnt(x + a.x, y + a.y); }
    int operator &(pnt a) { return x * a.x + y * a.y; }
    int operator ^(pnt a) { return x * a.y - y * a.x; }
}p[N], q[N];

int n, id[N];
long long ans;
double an[N];

bool cmp(int i, int j) { return an[i] < an[j] - ep; }

int main() {
///    freopen("D.in","r",stdin);
    scanf("%d", &n);
    if(n < 3) { puts("0"); return 0; }
    for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
    for(int i = 0; i < n; i ++) {
        int m = 0;
        for(int j = 0; j < n; j ++) if(i != j) q[m ++] = p[j] - p[i];
        for(int j = 0; j < m; j ++) {
            id[j] = j;
            if(q[j].y < 0 || q[j].y == 0 && q[j].x < 0) {
                q[j].y = -q[j].y; q[j].x = -q[j].x;
            }
            an[j] = atan2(q[j].y, q[j].x);
        }
        sort(id, id + m, cmp);
        for(int j = 0; j < m; j ++) {
            int k = j;
            while(k < m && (q[id[k]] ^ q[id[j]]) == 0) k ++;
            ans += (k - j) * (n - 1 - k + j);
            j = k - 1;
        }
    }
    printf("%I64d\n", ans / 6);
    return 0;
}
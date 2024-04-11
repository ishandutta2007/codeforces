#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

#define N 800005

typedef pair <int, int> PII;

int a[N];

vector <PII> V[N / 2];

int sto[N], rlt[N / 2], cnt;
int bit[N];

void add(int p, int v) {
    for (int i = p; i <= cnt; i += i & -i) if (bit[i] < v) bit[i] = v;
}

int calc(int p) {
    int rlt = 0;
    for (int i = p; i; i -= i & -i) if (rlt < bit[i]) rlt = bit[i];
    return rlt;
}

int pre[N / 2], cmax[N / 2], d[N / 2], first[N / 2];

main() {
    int n, m;
    cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i), sto[++ cnt] = a[i];
    for (int i = 1; i <= m; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(PII(b, i));
        sto[++ cnt] = b;
    }
    sort(sto + 1, sto + cnt + 1);
    cnt = unique(sto + 1, sto + cnt + 1) - sto - 1;

    int Max = 0;
    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(sto + 1, sto + cnt + 1, a[i]) - sto;
        int dis = calc(a[i] - 1) + 1;
        if (Max < dis) Max = dis;
        add(a[i], dis);
        d[i] = dis;
    }

    for (int i = n; i; i --) {
        int dis = d[i];
        if (dis < Max && cmax[dis + 1] <= a[i]) pre[i] = Max;
        else {
            if (!first[dis]) first[dis] = i, pre[i] = Max - 1;
            else {
                pre[i] = Max;
                pre[first[dis]] = Max;
            }
            if (cmax[dis] < a[i]) cmax[dis] = a[i];
        }
    }

    for (int i = 1; i <= cnt; i ++) bit[i] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < V[i].size(); j ++) {
            int b = lower_bound(sto + 1, sto + cnt + 1, V[i][j].first) - sto;
            int id = V[i][j].second;
            rlt[id] = 1 + calc(b - 1);
        }
        int p = a[i];
        int dis = calc(p - 1);
        add(p, dis + 1);
    }

    for (int i = 1; i <= cnt; i ++) bit[i] = 0;
    for (int i = n; i; i --) {
        for (int j = 0; j < V[i].size(); j ++) {
            int b = lower_bound(sto + 1, sto + cnt + 1, V[i][j].first) - sto;
            int id = V[i][j].second;
            rlt[id] += calc(cnt - b);
            if (rlt[id] < pre[i]) rlt[id] = pre[i];
        }
        int p = a[i];
        int dis = calc(cnt - p);
        add(cnt + 1 - p, dis + 1);
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", rlt[i]);
}
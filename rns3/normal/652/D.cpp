#include <bits/stdc++.h>
using namespace std;

#define M 500001

struct dat{
    int x, y, id;
    dat(int x = 0, int y = 0, int id = 0):x(x), y(y), id(id){}
}p[M];

bool cmp(dat A, dat B) {
    if(A.y - A.x != B.y - B.x) return A.y - A.x < B.y - B.x;
    return 0;
}

int bit[M], BIT[M], ans[M], sto[M];

int calc(int x) {
    int res = 0;
    while(x) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

void add(int x) {
    while(x < M) {
        bit[x] ++;
        x += x & -x;
    }
}

int CALC(int x) {
    int res = 0;
    while(x < M) {
        res += BIT[x];
        x += x & -x;
    }
    return res;
}

void ADD(int x) {
    while(x) {
        BIT[x] ++;
        x -= x & -x;
    }
}

int main() {
    ///freopen("d.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) scanf("%d %d", &p[i].x, &p[i].y), p[i].id = i, sto[cnt ++] = p[i].x, sto[cnt ++] = p[i].y;
    sort(sto, sto + cnt);
    cnt = unique(sto, sto + cnt) - sto;
    for(int i = 1; i <= n; i ++) {
        p[i].x = lower_bound(sto, sto + cnt, p[i].x) - sto + 1;
        p[i].y = lower_bound(sto, sto + cnt, p[i].y) - sto + 1;
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 0; i < M; i ++) bit[i] = BIT[i] = 0;
    for(int i = 1; i <= n; i ++) {
        int x = p[i].x, y = p[i].y, z = p[i].id;
        int xx = calc(x - 1);
        int yy = CALC(y + 1);
        ans[z] = i - 1 - xx - yy;
        add(x);
        ADD(y);
    }
    for(int i = 1; i <= n; i ++) printf("%d\n", ans[i]);
}
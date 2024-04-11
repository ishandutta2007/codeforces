#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, s;
long long sum, cur[2];

struct peo {
    int s, a, b;
    void input() {
        scanf("%d %d %d", &s, &a, &b);
    }
    bool operator < (const peo &p) const {
        return abs(a - b) < abs(p.a - p.b);
    }
} p[N], t[N];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i ++) {
        p[i].input();
        if (p[i].a < p[i].b) cur[0] += p[i].s;
        else cur[1] += p[i].s;
        sum += 1ll * p[i].s * max(p[i].a, p[i].b);
    }
    if ((cur[0] + cur[1] + s - 1) / s == (cur[0] + s - 1) / s + (cur[1] + s - 1) / s) return printf("%I64d\n", sum), 0;
    int cnt = 0;
    for (int i = 0; i < n; i ++) if (p[i].a < p[i].b) t[cnt++] = p[i];
    long long k = (cur[0] + s - 1) % s + 1, tmp = sum;
    sort(t, t + cnt);
    for (int i = 0; i < cnt; i ++) {
        tmp += min(k, 1ll * t[i].s) * (t[i].a - t[i].b);
        k -= t[i].s; if (k <= 0) break;
    }
    for (int i = cnt = 0; i < n; i ++) if (p[i].a >= p[i].b) t[cnt++] = p[i];
    k = (cur[1] + s - 1) % s + 1;
    sort(t, t + cnt);
    for (int i = 0; i < cnt; i ++) {
        sum += min(k, 1ll * t[i].s) * (t[i].b - t[i].a);
        k -= t[i].s; if (k <= 0) break;
    }
    printf("%I64d\n", max(tmp, sum));
}
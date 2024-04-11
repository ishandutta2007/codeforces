#include <cstdio>
#include <algorithm>
#include <cstdint>
//
using namespace std;

#define updiv(a, b) ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1)

struct Intv {
    int type : 2;
    int from : 23;
    int to : 23;
};

int n; int r[100005];
Intv f[100005][17][17];

Intv un(Intv a, Intv b)
{
    Intv c;
    if (a.type == 0 && b.type == 0) {
        c.type = 0;
        c.from = min(a.from, b.from);
        c.to = max(a.to, b.to);
    } else if (a.type == 1 && b.type == 1) {
        if (a.to < b.from || b.to < a.from) {
            c.type = 0; c.from = 0; c.to = n - 1;
        } else {
            c.type = 1;
            c.from = max(a.from, b.from);
            c.to = min(a.to, b.to);
        }
    } else {
        if (b.type == 1) {
            Intv t = a; a = b; b = t;
        }
        if (b.from <= a.from && a.to <= b.to) {
            c.type = 0; c.from = 0; c.to = n - 1;
        } else {
            c = a;
            if (a.to < b.from || b.to < a.from) return c;
            if (b.to >= a.to) {
                c.to = b.from - 1;
            } else {
                c.from = b.to + 1;
            }
        }
    }
    return c;
}

Intv expand(Intv intv, int time_pwr)
{
    if (intv.type == 0) {
        int cur = intv.from;
        bool began = false; Intv curintv;
        int len = intv.to - intv.from + 1;
        for (int i = 16; i >= 0; i--) {
            if (len & (1 << i)) {
                if (!began) {
                    curintv = f[cur][i][time_pwr]; began = true;
                } else {
                    curintv = un(curintv, f[cur][i][time_pwr]);
                }
                cur += (1 << i);
            }
        }
        return curintv;
    } else {
        Intv left, right;
        left.type = right.type = 0;
        left.from = 0; left.to = intv.from - 1;
        right.from = intv.to + 1; right.to = n - 1;
        return un(expand(left, time_pwr), expand(right, time_pwr));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", r + i);
    }
    if (n == 1) {
        printf("0"); return 0;
    }
    for (int i = 0; i < n; i++) {
        if (r[i] >= updiv(n - 1, 2)) {
            f[i][0][0].type = 0; f[i][0][0].from = 0;
            f[i][0][0].to = n - 1;
        } else {
            if (i < r[i]) {
                f[i][0][0].type = 1; f[i][0][0].from = i + r[i] + 1;
                f[i][0][0].to = (i - r[i] + n) % n - 1;
            } else if (i + r[i] >= n) {
                f[i][0][0].type = 1; f[i][0][0].from = (i + r[i]) % n + 1;
                f[i][0][0].to = i - r[i] - 1;
            } else {
                f[i][0][0].type = 0; f[i][0][0].from = i - r[i];
                f[i][0][0].to = i + r[i];
            }
        }
    }
    for (int pwr = 1; pwr <= 16; pwr++) {
        for (int i = 0; i < n; i++) {
            f[i][pwr][0] = un(f[i][pwr - 1][0], f[(i + (1 << (pwr - 1))) % n][pwr - 1][0]);
        }
    }
    for (int pwr2 = 1; pwr2 <= 16; pwr2++) {
        for (int i = 0; i < n; i++) {
            f[i][0][pwr2] = expand(f[i][0][pwr2 - 1], pwr2 - 1);
        }
        for (int pwr1 = 1; pwr1 <= 16; pwr1++) {
            for (int i = 0; i < n; i++) {
                f[i][pwr1][pwr2] = un(f[i][pwr1 - 1][pwr2], f[(i + (1 << (pwr1 - 1))) % n][pwr1-1][pwr2]);
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int pwr1 = 0; pwr1 <= 3; pwr1++) {
            for (int pwr2 = 0; pwr2 <= 3; pwr2++) {
                printf("[%d %d] %d seconds: type %d, [%d %d]\n", i + 1, (i + (1 << pwr1) + n - 1) % n + 1,
                    (1 << pwr2), f[i][pwr1][pwr2].type, f[i][pwr1][pwr2].from + 1, f[i][pwr1][pwr2].to + 1);
            }
        }
    }*/
    for (int idx = 0; idx < n; idx++) {
        Intv cur; cur.type = 0; cur.from = cur.to = idx;
        int tim = 0;
        for (int i = 16; i >= 0; i--) {
            Intv newintv = expand(cur, i);
            if (newintv.type || newintv.from != 0 || newintv.to != n - 1) {
                cur = newintv; tim += (1 << i);
            }
        }
        printf("%d ", tim + 1);
    }
    return 0;
}
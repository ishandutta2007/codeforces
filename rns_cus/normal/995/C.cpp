#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, c[N];

struct pnt{
    int x, y;
    pnt(int x = 0, int y = 0) : x(x), y(y) {}
    pnt operator + (pnt p) {
        return pnt(x + p.x, y + p.y);
    }
    pnt operator * (int a) {
        return pnt(a * x, a * y);
    }
    bool operator & (pnt p) {
        return 1ll * x * p.x + 1ll * y * p.y > 0;
    }
    void input() {scanf("%d %d", &x, &y);}
    bool norm() {
        return 1ll * x * x + 1ll * y * y <= 1e12;
    }
} p[N];

void solve(int n) {
    if (n <= 2) {
        c[1] = 1;
        if (p[1] & p[2]) c[2] = -1;
        else c[2] = 1;
        return;
    }
    int x, y, a;
    for (int i = n - 2; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = -1; k <= 1; k += 2) {
                if ((p[i] + p[j] * k).norm()) {
                    x = i, y = j, a = k;
                    goto last;
                }
            }
        }
    }
    assert(0);
    last:
        p[x] = p[x] + p[y] * a, p[y] = p[n];
        solve(n - 1);
        c[n] = c[y], c[y] = c[x] * a;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) p[i].input();
    solve(n);
    for (int i = 1; i <= n; i ++) printf("%d\n", c[i]);
}
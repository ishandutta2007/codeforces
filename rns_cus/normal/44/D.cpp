#include <bits/stdc++.h>
using namespace std;

#define N 5050

struct pnt {
    int x, y, z;
    pnt(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    pnt operator - (const pnt &p) {
        return pnt(x - p.x, y - p.y, z - p.z);
    }
    double dist() {
        return sqrt(x * x + y * y + z * z);
    }
    void in() {
        scanf("%d %d %d", &x, &y, &z);
    }
} p[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) p[i].in();
    double ans = 1e9;
    for (int i = 1; i < n; i ++) for (int j = 1; j < i; j ++) ans = min(ans, (p[0] - p[i]).dist() + (p[0] - p[j]).dist() + (p[i] - p[j]).dist());
    printf("%.8lf\n", ans / 2);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define N 2005

typedef long long ll;
const double ep = 1e-12;
int n, a[N], b[N], c[N];
double al[N];

struct pnt {
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator- (const pnt &b) const { return pnt(x - b.x, y - b.y); }
} p[N], q[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        int r = a[i] * a[i] + b[i] * b[i];
        p[i] = pnt(1.0 * a[i] * c[i] / r, 1.0 * b[i] * c[i] / r);
    }
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        int k = 0;
        for(int j = 0; j < n; j ++) if(i != j) q[k ++] = p[j] - p[i];
        int t = 0;
        for(int j = 0; j < k; j ++) {
            if(q[j].x < -ep) q[j].x = -q[j].x, q[j].y = -q[j].y;
            else if(q[j].x < ep && q[j].y < -ep) q[j].x = -q[j].x, q[j].y = -q[j].y;
            if(abs(q[j].x) < ep && abs(q[j].y) < ep) ans += n - 2;
            else al[t ++] = atan2(q[j].x, q[j].y);
        }
        if(t > 1) sort(al, al + t);
        int tp = 1;
        for(int j = 1; j < t; j ++) {
            if(abs(al[j] - al[j-1]) < ep) tp ++;
            else {
                ans += 1LL * tp * (tp - 1) / 2;
                tp = 1;
            }
        }
        ans += 1LL * tp * (tp - 1) / 2;
    }
    printf("%I64d\n", ans / 3);
    return 0;
}
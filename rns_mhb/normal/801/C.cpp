#include<bits/stdc++.h>
using namespace std;

struct device{
    int a, b;
    bool operator < (const device &x) {return 1ll * b * x.a < 1ll * x.b * a;}
    void in() {scanf("%d%d", &a, &b);}
} d[100010];

int main() {
    int i, n, p;
    long long A = 0, B = 0;
    scanf("%d%d", &n, &p);
    for(i = 1; i <= n; i ++) d[i].in();
    sort(d + 1, d + n + 1);
    for(i = 1; i <= n; i ++) {
        A += 1ll * d[i].a;
        B += 1ll * d[i].b;
        if(A <= p) continue;
        if((A - p) * d[i].b > B * d[i].a) continue;
        if(i < n && (A - p) * d[i + 1].b < B * d[i + 1].a) continue;
        printf("%lf\n", 1.0 * B / (A - p));
        break;
    }
    if(i > n) puts("-1");
}
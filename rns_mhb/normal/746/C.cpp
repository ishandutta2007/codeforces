#include<bits/stdc++.h>
using namespace std;

int s, x[2], t[2], p, d;

int main() {
    scanf("%d %d %d %d %d %d %d", &s, &x[0], &x[1], &t[0], &t[1], &p, &d);
    int tt;
    if (x[0] > x[1]) d = -d, p = s - p, x[0] = s - x[0], x[1] = s - x[1];
    if (d == 1) tt = x[1] - p + (p <= x[0] ? 0 : 2 * s);
    else tt = p + x[1];
    printf("%d\n", min(tt * t[0], (x[1] - x[0]) * t[1]));

    return 0;
}
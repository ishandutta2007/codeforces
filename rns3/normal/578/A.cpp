#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	//freopen("A.in", "r", stdin);
	scanf("%d %d", &a, &b);
	if (a < b) return puts("-1"), 0;
	if (a == b) return printf("%d\n", a), 0;
    int d = a - b;
    double ans = 1e10, tmp;
    int r = d / (2 * b);
    if (r) ans = 1. * d / 2 / r;
    d = (a + b); r = d / (2 * b);
    tmp = 1. * d / 2 / r;
    if (ans > tmp) ans = tmp;
    printf("%.12lf\n", ans);
}
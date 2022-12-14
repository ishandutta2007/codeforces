#include <bits/stdc++.h>
using namespace std;

int l[1000001], r[1000001];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i ++) scanf("%d %d", &l[i], &r[i]);
    double ans = 0;
    for(int i = 0; i < n; i ++) {
        int x = r[i] / p - (l[i] - 1) / p;
        int len1 = r[i] - l[i] + 1;
        int j = (i + 1) % n;
		int y = r[j] / p - (l[j] - 1) / p;
		int len2 = r[j] - l[j] + 1;
        long long z = 1ll * x * len2 + 1ll * y * len1 - 1ll * x * y;
        ans += 1. * z / len1 / len2;
    }
    printf("%.10lf\n", 2000. * ans);
}
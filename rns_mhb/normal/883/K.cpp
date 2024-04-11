#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long

int a[N], b[N], n;
int s[N], t[N];
ll ans;

int main() {
    int h;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
    for (int i = 1; i <= n; i ++) s[i] = a[i] + b[i] + i;
    for (int i = n - 1; i; i --) s[i] = min(s[i], s[i+1]);
    bool flag = 0;
    t[0] = 1e9;
    for (int i = 1; i <= n && !flag; i ++) {
        h = s[i] - i;
        if (a[i] > h) flag = 1;
        t[i] = min(h, b[i] + a[i]);
        t[i] = min(t[i], t[i-1] + 1);
        if (t[i] < a[i]) flag = 1;
    }
    if (flag) puts("-1");
    else {
		for (int i = 1; i <= n; i ++) ans += t[i] - a[i];
		printf("%I64d\n", ans);
		for (int i = 1; i <= n; i ++) printf("%d ", t[i]);
    }
    return 0;
}
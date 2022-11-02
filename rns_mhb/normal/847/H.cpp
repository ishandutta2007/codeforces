#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n, a[N], b[N];
long long now;

void make(int i, int val) {
	now += val - b[i];
	b[i] = val;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	b[1] = a[1];
	for (int i = 2; i <= n; i ++) b[i] = max(a[i], b[i-1] + 1);
    for (int i = 1; i <= n; i ++) now += b[i];
    a[n+1] = -10;
    long long ans = now;
    for (int i = n - 1, val; i >= 1; i --) {
    	val = max(b[i+2] + 1, a[i+1]);
    	make(i + 1, val);
    	if (b[i] <= b[i+1]) val = b[i+1] + 1, make(i, val);
    	ans = min(ans, now);
    }
    for (int i = 1; i <= n; i ++) ans -= a[i];
    printf("%I64d\n", ans);

	return 0;
}
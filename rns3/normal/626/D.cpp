#include <bits/stdc++.h>
using namespace std;

#define N 5000

int a[N];

long long s[N];

int x[N], n;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
	sort (x + 1, x + n + 1);
	for (int i = 1; i < n; i ++) for (int j = i + 1; j <= n; j ++) a[x[j]-x[i]] ++;
    long long ans = 0, tot = n * (n - 1) / 2;
    tot = tot * tot * tot;
    for (int i = 1; i < N; i ++) s[i] = s[i-1] + a[i];
    for (int i = N - 1; i >= 3; i --) for (int j = i - 2; j >= 1; j --) ans += s[i-j-1] * a[i] * a[j];
    double rlt = 1.0 * ans / tot;
    printf("%.7lf\n", rlt);

	return 0;
}
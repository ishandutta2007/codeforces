#include <bits/stdc++.h>
using namespace std;

int n, a[100100];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i < n; i ++) if (a[i] < a[i-1]) ans += a[i-1] - a[i];
	cout << ans << endl;
	return 0;
}
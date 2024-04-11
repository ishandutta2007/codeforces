#include <bits/stdc++.h>
using namespace std;

#define M 300001

int x[M], y[M], cnt1[M], cnt2[M];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d %d", &x[i], &y[i]);
		cnt1[x[i] + y[i] + 2000] ++;
		cnt2[x[i] - y[i] + 2000] ++;
	}
	long long ans = 0;
	for(int i = 0; i < M; i ++) ans += 1ll * cnt1[i] * (cnt1[i] - 1) / 2;
	for(int i = 0; i < M; i ++) ans += 1ll * cnt2[i] * (cnt2[i] - 1) / 2;
	cout << ans << endl;
}
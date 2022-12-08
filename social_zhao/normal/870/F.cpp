#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e7 + 5;
int n;
int pri[N], tot, mn[N], cnt[N], sum[N], phi[N], vis[N];

void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i, mn[i] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1, mn[i * pri[j]] = min(mn[i], pri[j]);
			if(i % pri[j] == 0) { phi[i * pri[j]] = phi[i] * pri[j]; break; }
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
	for(int i = 2; i <= n; i++) ++cnt[mn[i]];
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];
}

int GetSum(int l, int r) { return l <= r? sum[r] - sum[l - 1] : 0; }

main() {
	n = get();
	init(n);
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	ans1 = n * (n - 1) / 2;
	for(int i = 1; i <= n; i++) ans1 -= phi[i];
	for(int i = 2; i <= n; i++) {
		if(vis[i]) continue;
		ans3 += cnt[i] * GetSum(max(i + 1, n / i + 1), n / 2);
		ans4 += cnt[i] * GetSum(max(i + 1, max(n / 2 + 1, n / i + 1)), n);
	}
	ans2 = n * (n - 1) / 2 - n + 1 - ans1 - ans3 - ans4;
	cout << ans1 + ans2 * 2 + ans3 * 3 << endl;
	return 0;
}
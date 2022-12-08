#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3005;
int n, k, a[N], cnt[N], sum[N];

main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get(), cnt[i] = cnt[i - 1] + (a[i] == 0), sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	if(abs(sum[n]) - k * cnt[n] > 0) { cout << -1 << endl; return 0; }
	for(int mx = 0; mx <= n; mx++) {
		for(int mn = 0; mn <= n; mn++) {
			if(mx == mn) continue;
			int cnt0 = cnt[max(mx, mn)] - cnt[min(mx, mn)], other = cnt[n] - cnt0;
			int delt = sum[mx] - sum[mn];
			int maxd;
			if(mx < mn) maxd = min(cnt0 * k, sum[n] + other * k);
			else maxd = min(cnt0 * k, -sum[n] + other * k);
			ans = max(ans, delt + maxd);
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
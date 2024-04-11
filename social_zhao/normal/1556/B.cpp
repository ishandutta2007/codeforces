#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int cnt[2], n, a[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get() & 1, ++cnt[a[i]];
	int ans = 0x3f3f3f3f3f3f3f3f;
	if(cnt[0] == cnt[1]) {
		int now = 0, res = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 0) ++now, res += abs(i - 2 * now);
		ans = min(ans, res);
		now = 0, res = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1) ++now, res += abs(i - 2 * now);
		ans = min(ans, res);
	}
	else if(cnt[0] == cnt[1] + 1) {
		int now = 0, res = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1) ++now, res += abs(i - 2 * now);
		ans = min(ans, res);
	}
	else if(cnt[1] == cnt[0] + 1) {
		int now = 0, res = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 0) ++now, res += abs(i - 2 * now);
		ans = min(ans, res);
	}
	else ans = -1;
	printf("%d\n", ans);
	cnt[0] = cnt[1] = 0;
}

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}
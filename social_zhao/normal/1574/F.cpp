#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, P = 998244353;
int n, m, k, pre[N], suf[N], f[N], a[N], ban[N], cnt[N], w[N], v[N], tot;

signed main() {
	n = get(), m = get(), k = get();
	for(int t = 1; t <= n; t++) {
		int len = get();
		for(int i = 1; i <= len; i++) a[i] = get();
		int flag = 1;
		for(int i = 2; i <= len; i++) {
			if(pre[a[i]] && pre[a[i]] != a[i - 1]) { flag = 0; continue; }
			if(suf[a[i - 1]] && suf[a[i - 1]] != a[i]) { flag = 0; continue; }
			pre[a[i]] = a[i - 1], suf[a[i - 1]] = a[i];
		}
		if(!flag) for(int i = 1; i <= len; i++) ban[a[i]] = 1;
	}
	for(int i = 1; i <= k; i++) {
		if(pre[i]) continue;
		int flag = 0;
		for(int now = i; now; now = suf[now]) flag |= ban[now];
		if(!flag) {
			int len = 0;
			for(int now = i; now; now = suf[now]) ++len;
			cnt[len]++;
		}
	}
	for(int i = 1; i <= k; i++) if(cnt[i]) ++tot, w[tot] = i, v[tot] = cnt[i];
	f[0] = 1;
	for(int i = 0; i <= m; i++)
		for(int j = 1; j <= tot; j++)
			if(w[j] <= i) f[i] = (f[i] + v[j] * f[i - w[j]] % P) % P;
	printf("%lld\n", f[m]);
	return 0;
}

//114514
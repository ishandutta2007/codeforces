#include<bits/stdc++.h>
using namespace std;

inline int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int n, m, a[N], b[N], l[N], p[N], f[N], g[N], ans[N];
bool vis[N];

int main() {
	n = get();
	for(register int i = 1; i <= n; i++) a[i] = get(), f[i] = inf;
	m = get();
	for(register int i = 1; i <= m; i++) b[i] = get();
	sort(b + 1, b + 1 + m);
	a[++n] = inf, f[n] = inf;
	for(register int i = 1; i <= n; i++) {
		if(a[i] != -1) {
			int j = lower_bound(f + 1, f + 1 + n, a[i]) - f - 1;
			f[j + 1] = a[i], g[j + 1] = i, l[i] = j + 1, p[i] = g[j];
		}
		else {
			for(register int j = n, k = m; k; k--) {
				while(f[j] >= b[k]) --j;
				f[j + 1] = b[k], g[j + 1] = i;
			}
		}
	}
	int now = l[n], val = a[n], pos = n;
	while(now--) {
		if(a[pos] != -1) {
			if(a[p[pos]] == -1) {
				int i = lower_bound(b + 1, b + 1 + m, a[pos]) - b - 1;
				vis[i] = 1, val = ans[p[pos]] = b[i];
			} 
			else val = a[p[pos]];
			pos = p[pos];
		}
		else {
			bool found = 0;
			for(register int j = pos - 1; j >= 1; j--) {
				if(a[j] != -1 && l[j] == now && a[j] < val) { 
					pos = j, val = a[j], found = 1; break; 
				}
			}
			if(found) continue;
			for(register int j = pos - 1; j; j--) {
				if(a[j] == -1) {
					int i = lower_bound(b + 1, b + 1 + m, val) - b - 1;
					vis[i] = 1, val = ans[j] = b[i];
					pos = j;
					break;
				}
			}
		}
	}
	int j = 1;
	for(register int i = 1; i <= n; i++) {
		if(a[i] == -1) {
			if(ans[i]) continue;
			while(vis[j]) ++j;
			vis[j] = 1;
			ans[i] = b[j];
		}
		else ans[i] = a[i];
	}
	for(register int i = 1; i < n; i++) printf("%d ", ans[i]);
	return 0;
}
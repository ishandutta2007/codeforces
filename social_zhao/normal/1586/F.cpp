#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, k, bel[N], tot, ans[N][N], mx;

void solve(int l, int r, int dep) {
	if(l == r) return;
	int len = (r - l + 1 + (k - 1)) / k;
	for(int i = l, nxt; i <= r; i = nxt + 1) {
		nxt = min(r, i + len - 1), ++tot;
		for(int j = i; j <= nxt; j++) bel[j] = tot;
	}
	for(int i = l; i <= r; i++)
		for(int j = i + 1; j <= r; j++)
			if(bel[i] != bel[j]) ans[i][j] = dep;
	for(int i = l, nxt; i <= r; i = nxt + 1) {
		nxt = min(r, i + len - 1);
		solve(i, nxt, dep + 1);
	}
}

int main() {
	n = get(), k = get();
	solve(1, n, 1);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			mx = max(mx, ans[i][j]);
	cout << mx << endl;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			cout << ans[i][j] << " ";
	return 0;
}
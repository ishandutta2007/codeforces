#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 305;
int n, m, k, a[N * N], b[N * N], len, cnt[N * N], vis[N][N];
pair<int, int> pos[N * N];
priority_queue<pair<int, int> > q[N * N];

void Next(int &x, int &y) {
	++y;
	if(y == m + 1) ++x, y = 1;
}

void solve() {
	n = get(), m = get(), k = n * m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			vis[i][j] = 0;
	for(int i = 1; i <= k; i++) a[i] = b[i] = get();
	sort(b + 1, b + 1 + k), len = unique(b + 1, b + 1 + k) - b - 1;
	for(int i = 1; i <= len; i++) cnt[i] = 0;
	for(int i = 1; i <= k; i++) a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b, ++cnt[a[i]];
	int nowx = 1, nowy = 1;
	for(int i = 1; i <= len; i++) 
		for(int j = 1; j <= cnt[i]; j++)
			q[i].push({-nowx, nowy}), Next(nowx, nowy);
	for(int i = 1; i <= k; i++)
		pos[i].first = -q[a[i]].top().first, pos[i].second = q[a[i]].top().second, q[a[i]].pop();
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		int x = pos[i].first, y = pos[i].second;
		for(int j = 1; j < y; j++) ans += vis[x][j];
		vis[x][y] = 1;
	}
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4 2
6 6 6 6 2 2 9 6
*/
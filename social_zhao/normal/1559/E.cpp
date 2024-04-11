#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 55, M = 1e5 + 5, P = 998244353;
int n, _m, _l[N], _r[N], m, l[N], r[N];
int pri[M], mu[M], vis[M], tot;
int f[2][M], sum[M];

void add(int &x, int y) { x = (x + y >= P)? (x + y - P) : (x + y); }
void dec(int &x, int y) { x = (x - y < 0)? (x - y + P) : (x - y); }

void init(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) mu[i] = -1, pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if((i % pri[j]) == 0) break;
			mu[i * pri[j]] = -mu[i];
		}
	}
}

int GetSum(int l, int r) {
	l = max(l, 0);
	if(l > r) return 0;
	if(l == 0) return sum[r];
	int res = sum[r];
	dec(res, sum[l - 1]);
	return res;
} 

int solve(int d) {
	m = _m / d;
	for(int i = 1; i <= n; i++) l[i] = (_l[i] + d - 1) / d, r[i] = _r[i] / d;
	for(int i = 0; i <= m; i++) f[0][i] = f[1][i] = 0;
	int now = 0, pre = 1;
	f[now][0] = 1;
	for(int t = 1; t <= n; t++) {
		swap(now, pre);
		for(int i = 0; i <= m; i++) f[now][i] = 0;
		sum[0] = f[pre][0];
		for(int i = 1; i <= m; i++) sum[i] = sum[i - 1], add(sum[i], f[pre][i]);
		for(int i = 0; i <= m; i++) 
			add(f[now][i], GetSum(i - r[t], i - l[t]));
	}
	int res = 0;
	for(int i = 0; i <= m; i++) add(res, f[now][i]);
	return res;
}

int main() {
	n = get(), _m = get();
	init(_m);
	for(int i = 1; i <= n; i++) _l[i] = get(), _r[i] = get();
	int ans = 0;
	for(int d = 1; d <= _m; d++) ans = (ans + mu[d] * solve(d)) % P;
	printf("%d\n", (ans + P) % P);
	return 0;
}
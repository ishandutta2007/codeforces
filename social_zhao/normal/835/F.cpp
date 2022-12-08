#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n;
struct Edge { int v, nxt, w; } edge[N << 1];
int head[N], tot = 1;
int cir[N], cnt, st[N], top, flag, ins[N], vis[N], dis[N];
int fir[N], sec[N];

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

void GetCircle(int u, int fa) {
	if(flag) return;
	st[++top] = u, ins[u] = 1;
	for(int i = head[u]; i && !flag; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w;
		if(i == fa) continue;
		dis[v] = w;
		if(!ins[v]) GetCircle(v, i ^ 1);
		else {
			while(st[top] != v) 
				cir[++cnt] = st[top--];
			cir[++cnt] = st[top--], flag = 1;
			return;
		}
	}
	if(st[top] == u) ins[st[top--]] = 0;
}

void dfs(int u) {
	vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w;
		if(vis[v]) continue;
		dfs(v);
		if(fir[v] + w > fir[u]) sec[u] = fir[u], fir[u] = fir[v] + w;
		else if(fir[v] + w > sec[u]) sec[u] = fir[v] + w;
	}
}

int q[N], l = 1, r = 0, tmp[N], pre[N], suf[N], A[N], B[N], C[N], D[N];

int solve(int s) {
	int res = 0x3f3f3f3f3f3f3f3f;
	while(top) ins[st[top--]] = 0;
	while(cnt) cir[cnt--] = 0; flag = 0;
	GetCircle(s, 0);
	for(int i = 1; i <= cnt; i++) vis[cir[i]] = 1, tmp[i % cnt + 1] = dis[cir[i]];
	for(int i = 1; i <= cnt; i++) dfs(cir[i]);
	for(int i = 1; i <= cnt; i++) cir[i + cnt] = cir[i], tmp[i + cnt] = tmp[i]; 
	for(int i = 2; i <= cnt; i++) pre[i] = pre[i - 1] + tmp[i];
	for(int i = cnt - 1; i >= 1; i--) suf[i] = pre[cnt] - pre[i];
	A[0] = -0x3f3f3f3f3f3f3f3f, B[cnt + 1] = -0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= cnt; i++) 
		A[i] = max(A[i - 1], fir[cir[i]] + pre[i]);
	for(int i = cnt; i >= 1; i--) 
		B[i] = max(B[i + 1], fir[cir[i]] + suf[i]);
	l = 1, r = 0, q[++r] = 1;
	for(int i = 2; i <= cnt; i++) {
		while(l <= r && q[l] <= i - cnt) l++;
		if(l <= r) C[i] = max(fir[cir[i]] + pre[i] - pre[q[l]] + fir[cir[q[l]]], C[i - 1]);
		while(l <= r && -pre[q[r]] + fir[cir[q[r]]] < -pre[i] + fir[cir[i]]) r--;
		q[++r] = i;
	}
	l = 1, r = 0, q[++r] = cnt;
	for(int i = cnt - 1; i >= 1; i--) {
		while(l <= r && q[l] >= i + cnt) l++;
		if(l <= r) D[i] = max(fir[cir[i]] + suf[i] - suf[q[l]] + fir[cir[q[l]]], D[i + 1]);
		while(l <= r && -suf[q[r]] + fir[cir[q[r]]] < -suf[i] + fir[cir[i]]) r--;
		q[++r] = i;
	}
	for(int i = 1; i < cnt; i++) 
		res = min(res, max((A[i] + B[i + 1] + tmp[1]), max(C[i], D[i + 1])));
	res = min(res, C[cnt]);
	return res;
}

signed main() {
	n = get();
	for(int i = 1, u, v, w; i <= n; i++) u = get(), v = get(), w = get(), add(u, v, w), add(v, u, w);
	int ans = 0;
	ans = solve(1);
	for(int i = 1; i <= n; i++) ans = max(ans, fir[i] + sec[i]);
	printf("%lld\n", ans);
	return 0;
}
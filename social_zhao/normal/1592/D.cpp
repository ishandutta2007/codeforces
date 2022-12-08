#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, u[N], v[N], maxd, bin[N << 1], top, shit;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int now, int lst) {
	if(lst) u[++shit] = lst, v[shit] = now;
	for(int i = head[now]; i; i = edge[i].nxt) {
		if(edge[i].v != lst) 
			dfs(edge[i].v, now);
	}
}

void solve(int l, int r) {
	if(l == r) {
		cout << "! " << u[l] << " " << v[l] << endl;
		exit(0);
	}
	int mid = (l + r) >> 1, now;
	top = 0;
	for(int i = l; i <= mid; i++) bin[++top] = u[i], bin[++top] = v[i];
	sort(bin + 1, bin + 1 + top), top = unique(bin + 1, bin + 1 + top) - bin - 1;
	cout << "? " << top << " "; for(int i = 1; i <= top; i++) cout << bin[i] << " "; cout << endl;
	cout.flush();
	cin >> now;
	if(now == maxd) solve(l, mid);
	else solve(mid + 1, r);
}

int main() {
	cin >> n;
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, add(u, v), add(v, u);
	dfs(1, 0);
	cout << "? " << n << " "; for(int i = 1; i <= n; i++) cout << i << " "; cout << endl;
	cout.flush();
	cin >> maxd;
	solve(1, n - 1);
	return 0;
}
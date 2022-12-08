#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, A[N], B[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, f[N][2];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void qmin(int &x, int y) { x = min(x, y); }

void dfs(int u, int lst) {
	vector<int> bin;
	int sum = 0, a = 0, b = 0;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u);
		if(B[u] < B[v]) sum += f[v][0], ++a;
		else if(B[u] > B[v]) sum += f[v][1], ++b;
		else sum += f[v][0], ++a, bin.push_back(f[v][1] - f[v][0]);
	}
	sort(bin.begin(), bin.end(), [](int x, int y){ return x < y; });
	f[u][0] = sum + max(a, b + (lst != 0)) * A[u];
	f[u][1] = sum + max(a + (lst != 0), b) * A[u];
	for(int i = 0; i < bin.size(); i++) {
		sum += bin[i], a--, b++;
		qmin(f[u][0], sum + max(a, b + (lst != 0)) * A[u]);
		qmin(f[u][1], sum + max(a + (lst != 0), b) * A[u]);
	}
}

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) A[i] = get();
	for(int i = 1; i <= n; i++) B[i] = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	memset(f, 0x3f, sizeof(f));
	dfs(1, 0);
	cout << f[1][0];
	return 0;
}
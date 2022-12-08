#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, cnt[2], col[N];
vector<int> bin[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int c) {
	if(col[u] != -1) return;
	col[u] = c, cnt[c] = (cnt[c] + u) % (2 * n);
	for(int i = head[u]; i; i = edge[i].nxt) dfs(edge[i].v, c ^ 1);
}

int main() {
	cin >> n;
	if((n & 1) == 0) {
		cout << "First" << endl;
		for(int i = 1; i <= 2 * n; i++) cout << (i - 1) % n + 1 << " ";
		cout << endl, cout.flush();
	}
	else {
		cout << "Second" << endl, cout.flush();
		for(int i = 1; i <= n; i++) add(i, i + n), add(i + n, i);
		for(int i = 1, u; i <= 2 * n; i++) cin >> u, bin[u].push_back(i);
		for(int i = 1; i <= n; i++) {
			int u = bin[i][0], v = bin[i][1];
			add(u, v), add(v, u);
		}
		memset(col, -1, sizeof(col));
		for(int i = 1; i <= 2 * n; i++) dfs(i, 0);
//		for(int i = 1; i <= 2 * n; i++) cout << col[i] << endl;
		int flag;
		if(cnt[0] == 0) flag = 0;
		else flag = 1;
		for(int i = 1; i <= 2 * n; i++) if(col[i] == flag) cout << i << " ";
		cout << endl; cout.flush();
	}
	return 0;
}
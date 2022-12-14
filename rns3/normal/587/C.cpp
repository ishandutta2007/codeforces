#include <cstdio>
#include <algorithm>

using namespace std;

#define N 100005

struct RLT {
	int cnt, a[15];
	void add(int x) {
		for (int i = 0; i < cnt; i ++) {
			if (x < a[i]) {
				for (int j = cnt + 1; j > i; j --) a[j] = a[j - 1];
				a[i] = x;
				if (cnt < 10) cnt ++;
				return;
			}
		}
		if (cnt < 10) a[cnt ++] = x;
	}
	RLT operator + (const RLT &r) const {
		RLT ret;
		int x, y, z;
		for (x = y = z = 0; x < 10; x ++) {
			if (y == cnt && z == r.cnt) break;
			if (y == cnt) ret.a[x] = r.a[z], z ++;
			else if (z == r.cnt) ret.a[x] = a[y], y ++;
			else if (a[y] < r.a[z]) ret.a[x] = a[y], y ++;
			else ret.a[x] = r.a[z], z ++;
		}
		ret.cnt = x;
		return ret;
	}
};

RLT x[20][N];
int p[20][N], dp[N];
int head[N], to[N << 1], nxt[N << 1];

void AddEdge(int a, int b, int i) {
	to[i] = b;
	nxt[i] = head[a];
	head[a] = i;
}

RLT LCA(int a, int b) {
	if (dp[a] > dp[b]) swap(a, b);
	int D;
	RLT ret;
	ret.cnt = 0;
	for (D = 0; (1 << D) <= dp[b]; D ++); D --;
	for (int i = D; i >= 0; i --) {
		if (dp[a] <= dp[b] - (1 << i)) {
			ret = ret + x[i][b];
			b = p[i][b];
		}
	}
	if (a == b) return ret + x[0][a];
	for (int i = D; i >= 0; i --) if (dp[a] >= (1 << i)) {
		if (p[i][a] != p[i][b]) {
			ret = ret + x[i][a] + x[i][b];
			a = p[i][a];
			b = p[i][b];
		}
	}
	return ret + x[0][a] + x[0][b] + x[0][p[0][a]];
}

void DFS(int u, int pr = 0) {
	p[0][u] = pr;
	dp[u] = dp[pr] + 1;
	for (int i = 1; (1 << i) <= dp[u]; i ++) {
		p[i][u] = p[i - 1][p[i - 1][u]];
		x[i][u] = x[i - 1][u] + x[i - 1][p[i - 1][u]];
	}
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != pr) DFS(v, u);
	}
}

main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; i ++) {
    	int a, b;
		scanf("%d %d", &a, &b);
		AddEdge(a, b, i);
		AddEdge(b, a, i + n - 1);
    }
    for (int i = 1, ps; i <= m; i ++) {
		scanf("%d", &ps);
		x[0][ps].add(i);
    }
    DFS(1);
    while (q --) {
    	int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		RLT rlt = LCA(x, y);
		printf("%d", min(rlt.cnt, z));
		for (int i = 0; i < rlt.cnt && i < z; i ++) printf(" %d", rlt.a[i]);
		puts("");
    }
}
#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;
const int MAXK = 17;
const int inf = 100100;

int N, M;
int Q;

int par[MAXN];

int find(int x) {
	if (par[x] == x) {
		return x;
	}
	return par[x] = find(par[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;

}

vector<int> conn[MAXN];
int num[MAXN];

int cnt = 0;
int dfs(int cur, int prv = -1) {
	if (num[cur]) return num[cur];
	num[cur] = ++cnt;

	int ret = inf;
	repi(i, conn[cur]) {
		if (*i != prv) {
			int val = dfs(*i, cur);
			if (val < ret) {
				ret = val;
			}
			if (val <= num[cur]) {
				join(cur, *i);
			}
		}
	}

	return ret;
}

vector<int> conn2[MAXN];
int par2[MAXN][MAXK];
int level[MAXN];

void dfs2(int cur, int prv = 0, int depth = 0) {
	par2[cur][0] = prv;
	level[cur] = depth;
	repi(i, conn2[cur]) {
		if (*i != prv) {
			dfs2(*i, cur, depth + 1);
		}
	}
}

int lca(int a, int b) {
	if (level[a] < level[b]) swap(a, b);
	int diff = level[a] - level[b];
	for(int i = 0; i < MAXK; ++i) {
		if ((diff >> i) & 1) {
			a = par2[a][i];
		}
	}

	if (a == b) return b;

	for(int i = MAXK - 1; i >= 0; --i) {
		if (par2[a][i] != par2[b][i]) {
			a = par2[a][i];
			b = par2[b][i];
		}
	}
	return par2[a][0];
}

int edgea[MAXN];
int edgeb[MAXN];

int main() {
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edgea[i] = a;
		edgeb[i] = b;

		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	for(int i = 1; i <= N; ++i) {
		par[i] = i;
	}

	dfs(1);

	for(int i = 0; i < M; ++i) {
		int a = find(edgea[i]);
		int b = find(edgeb[i]);
		if (a != b) {
			conn2[a].push_back(b);
			conn2[b].push_back(a);
		}
	}

	dfs2(find(1));
//	printf("root = %d\n", find(1));

	for(int k = 1; k < MAXK; ++k) {
		for(int i = 1; i <= N; ++i) {
			if (par[i] == i) {
				par2[i][k] = par2[par2[i][k - 1]][k - 1];
			}
		}
	}

	scanf("%d", &Q);

	for(int q = 0; q < Q; ++q) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = find(a);
		b = find(b);
		int c = lca(a, b);
		int ans = level[a] + level[b] - 2 * level[c];
//		printf("a = %d, b = %d, c = %d\n", a, b, c);
		printf("%d\n", ans);
	}

	return 0;
}
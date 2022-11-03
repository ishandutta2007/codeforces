#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
vector<int> nei[300005], egs[300005], degs[300005];
bool lgl[300005];
int u[300005], v[300005];
int tag[300005];
int ans;

void dfs(int now) {
	lgl[now] = 1;
	for (int to : nei[now]) if (!lgl[to]) {
		egs[now].push_back(to);
		degs[now].push_back(to);
		degs[to].push_back(now);
		dfs(to);
	}
}

void dfs2(int now) {
	bool hv = 0;
	for (int to : egs[now]) {
		dfs2(to);
		if (tag[to]) {
			if (hv) hv = 0, --ans;
			else hv = 1;
		}
		tag[now] ^= tag[to];
	}
	if (!hv && tag[now]) ++ans;
}

vector<int> stk;

void findpath(int now, int lst, int dst) {
	stk.push_back(now);
	if (now == dst) {
		printf("%d\n", SZ(stk));
		for (int to : stk) printf("%d ", to);
		puts("");
	}
	for (int to : degs[now]) if (to != lst) findpath(to, now, dst);
	stk.pop_back();
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	dfs(1);
	int Q; scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d", u + i, v + i);
		tag[u[i]] ^= 1;
		tag[v[i]] ^= 1;
	}
	dfs2(1);
	if (ans) {
		puts("NO");
		printf("%d\n", ans);
		return 0;
	}
	puts("YES");
	for (int i = 1; i <= Q; ++i) findpath(u[i], 0, v[i]);
	return 0;
}
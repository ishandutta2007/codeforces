#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define sz(x) int((x).size())

const int MAXN = 100100;

vector<int> conn[MAXN];

int N, M;

bool vis[MAXN];

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	repi(i, conn[node]) {
		dfs(*i);
	}
}
bool ring() {
	if (M != N) return false;
	for(int i = 1; i <= N; ++i) vis[i] = false;
	dfs(1);
	for(int i = 1; i <=N; ++i) {
		if (!vis[i]) return false;
	}
	for(int i = 1; i <= N; ++i) {
		if (sz(conn[i]) != 2) return false;
	}
	return true;
}

bool bus() {
	if (M != N - 1) return false;
	int num1 = 0;

	for(int i = 1; i <= N; ++i) {
		int deg = sz(conn[i]);
		if (deg == 1) ++num1;
		else if (deg > 2) return false;
	}
	return num1 == 2;
}

bool star() {
	if (M != N - 1) return false;
	int num1 = 0;

	for(int i = 1; i <= N; ++i) {
		int deg = sz(conn[i]);
		if (deg == 1) ++num1;
	}
	return num1 == N - 1;
}

int main() {
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	if (ring()) {
		printf("ring topology\n");
	} else if (bus()) {
		printf("bus topology\n");
	} else if (star()) {
		printf("star topology\n");
	} else {
		printf("unknown topology\n");
	}

	return 0;
}
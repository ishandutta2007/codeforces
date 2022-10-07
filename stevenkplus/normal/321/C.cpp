#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100100;

int N;
int deg[MAXN];
int cnts[MAXN][26];
bool vis[MAXN];
int ans[MAXN];
vector<int> conn[MAXN];

int findpar(int x) {
	for(int i = 0; i < int(conn[x].size()); ++i) {
		if (!vis[conn[x][i]]) {
			return conn[x][i];
		}
	}
	return -1;
}

void go(int x) {
	vis[x] = true;
	for(int i = 26 - 1; i >= 0; --i) {
		if (cnts[x][i] >= 2) {
			ans[x] = i + 1;
			break;
		}
	}
	while (cnts[x][ans[x]]) {
		++ans[x];
	}
	++cnts[x][ans[x]];

	int p = findpar(x);
	if (p == -1) return;

	--deg[p];
	for(int i = ans[x]; i < 26; ++i) {
		cnts[p][i] += cnts[x][i];
	}
	if (deg[p] <= 1) {
		go(p);
	}
}

char getc(int ans) {
	return 'Z' - ans;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
		++deg[a];
		++deg[b];
	}

	for(int i = 1; i <= N; ++i) {
		if (!vis[i] && deg[i] <= 1) {
			go(i);
		}
	}

	for(int i = 1; i <= N; ++i) {
		if (i != 1) printf(" ");
		printf("%c", getc(ans[i]));
//		printf("%d\n", ans[i]);
	}
	printf("\n");
	return 0;
}
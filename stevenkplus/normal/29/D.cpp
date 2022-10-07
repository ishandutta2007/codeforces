#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin() , _##i = (a).end(); i != _##i; ++i)
const int MAXN = 310;

vector<int> conn[MAXN];
int first[MAXN];
int last[MAXN];

int N;

int K = 0;
int leaf[MAXN];

int cnt = 0;
void dfs(int cur, int prv = -1) {
	first[cur] = ++cnt;

	bool isleaf = true;
	repi(i, conn[cur]) {
		if (*i != prv) {
			dfs(*i, cur);
			isleaf = false;
		}
	}
	if (isleaf) {
		++K;
	}

	last[cur] = cnt;
}

int idx = 0;
int j = 0;
int ans[MAXN * 2];

bool dfs2(int cur, int prv = -1) {
	ans[idx] = cur;
	++idx;
	if (cur == leaf[j]) {
		++j;
	}

	vector<int> &v = conn[cur];
	int z = int(v.size());
	if (prv != -1) --z;
	for(int i = 0; i < z; ++i) {
		int nxt = 0;
		int targ = first[leaf[j]];
//		printf("searching for %d (%d)\n", leaf[j], targ);
		repi(j, v) {
			if (*j != prv) {
				if (first[*j] <= targ && targ <= last[*j]) {
					nxt = *j;
					break;
				}
			}
		}
		if (nxt) {
			if (!dfs2(nxt, cur)) return false;
			ans[idx] = cur;
			++idx;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	dfs(1);
	for(int i = 0; i < K; ++i) {
		scanf("%d", leaf + i);
	}

	if(dfs2(1)) {
		for(int i = 0; i < idx; ++i) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	 } else {
		 printf("-1\n");
	 }
	return 0;
}
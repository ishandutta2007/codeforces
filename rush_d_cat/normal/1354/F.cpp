#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 80;
const LL inf = 1e18;
int T, n, k;
struct Nod {
	int a, b, id;
	bool operator<(const Nod&o)const{
		return b < o.b;
	}
} nod[N], items[N];


LL dp[N][N]; int pre[N][N];
pair<LL, vector<int> > solve(int n, int ban, Nod items[]) {
	pair<LL, vector<int> > ans;
	for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) dp[i][j] = -inf;
	dp[0][0] = 0;
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (dp[i][j] + items[i+1].a + items[i+1].b * j >= dp[i+1][j+1]) {
				dp[i+1][j+1] = dp[i][j] + items[i+1].a + items[i+1].b * j;
				pre[i+1][j+1] = 1;
			}
			if (dp[i][j] + items[i+1].b * (k-1) >= dp[i+1][j]) {
				dp[i+1][j] = dp[i][j] + items[i+1].b * (k-1);
				pre[i+1][j] = 0;
			}
		}
	}
	ans.first = dp[n][k-1];
	int x = n, y = k - 1;
	bool flag[N] = {0};
	while (x) {
		//printf("#%d %d\n", x, y);
		if (pre[x][y]) {
			y--;
			flag[x] = 1;
		}
		x--;
	}
	//printf("ban = %d\n", ban);
	for (int i = 1; i <= n; i ++) if (flag[i] && items[i].id!=ban) {
		ans.second.push_back(items[i].id);
	}
	for (int i = 1; i <= n; i ++) if (flag[i] == 0 && items[i].id!=ban) {
		//printf("$ %d\n", items[i].id);
		ans.second.push_back(items[i].id);
		ans.second.push_back(- items[i].id);
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &nod[i].a, &nod[i].b);
			nod[i].id = i;
		}
		sort(nod + 1, nod + 1 + n);
		LL ans = 0; vector<int> ops;
		for (int i = 1; i <= n; i ++) {
			LL add = nod[i].a + (k-1) * nod[i].b; 
			int tot = 0;
			for (int j = 1; j <= n; j ++) {
				if (i != j) items[++tot] = nod[j];
			}
			pair<LL, vector<int> > res = solve(tot, nod[i].id, items);
			if (add + res.first >= ans) {
				ans = add + res.first;
				ops = res.second; 
				ops.push_back(nod[i].id);
			}
		}
		//printf("# %lld\n", ans);
		printf("%d\n", ops.size());
		for (auto x: ops) {
			printf("%d ", x);
		}
		printf("\n");
	}
}
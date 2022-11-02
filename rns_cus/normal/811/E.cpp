#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

int dp[N][11][11], col[N][11], n, m, Q, root[N * 10], cnt[N], dist[11][11][11];
bitset<11> cango[N][11];

int find_root(int x){
	assert(x < N * 11 && x >= 0);
	return (root[x] == x) ? x : root[x] = find_root(root[x]);
}

int merge(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	if(x == y) return 0;
	root[y] = x; return 1;
}

void prepare() {

	for(int i = 0; i <= m; i ++) for(int j = 0; j < n; j ++) root[i * n + j] = i * n + j;

	int cntt = 0;
	for(int i = 1; i <= m; i ++){
		cntt += n;
		for(int j = 1; j < n; j ++) if (col[i][j] == col[i][j-1]){
			cntt -= merge(i * n + j, i * n + j - 1);
		}

		if(i > 1){
			for(int j = 0; j < n; j ++) if (col[i][j] == col[i-1][j]){
				cntt -= merge(i * n + j, i * n + j - n);
			}
		}

		for(int j = 0; j < n; j ++){
			for(int k = j + 1; k < n; k ++) if(find_root(i * n + j) == find_root(i * n + k)){
				cango[i][j][k] = cango[i][k][j] = true;
			}
		} cnt[i] = cntt;

	}

	for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) dp[m+1][i][j] = m + 1;

	for(int i = m; i >= 1; i --){
		for(int j = 0; j < n; j ++){

			if(col[i][j] == col[i][j+1]){ dp[i][j][j+1] = i; }
			else { dp[i][j][j+1] = m + 1; }

			for(int k = j + 2; k < n; k ++){
				if(col[i][j] != col[i][k]){ dp[i][j][k] = m + 1; continue; }
				if(col[i][j] == col[i+1][j] && col[i][k] == col[i+1][k]) dp[i][j][k] = dp[i+1][j][k];
				else dp[i][j][k] = m + 1;
			}
		}

		for(int j = 0; j < n; j ++){
			for(int k = j + 1; k < n; k ++) dist[j][k][0] = dist[k][j][0] = dp[i][j][k];
		}

		for(int t = 1; t <= n; t ++){
			for(int j = 0; j < n; j ++){
				for(int k = 0; k < n; k ++){
					dist[j][k][t] = min(dist[j][k][t-1], max(dist[j][t-1][t-1], dist[t-1][k][t-1]));
				}
			}
		}

		for(int j = 0; j < n; j ++){
			for(int k = j + 1; k < n; k ++){
				dp[i][j][k] = dist[j][k][n];
			}
		}
	}
}

void query(int L, int R) {

	for(int i = 0; i < 2 * n; i ++){ root[i] = i; }

	int cntl = n, cntr = n;
	for(int j = 0; j < n; j ++){
		for(int k = j + 1; k < n; k ++){
			if(cango[L-1][j][k]) cntl -= merge(j, k);
			if(dp[L][j][k] <= R) cntr -= merge(n + j, n + k);
		}
	}

	int cntot = cntl + cntr;

	for(int j = 0; j < n; j ++) if(col[L-1][j] == col[L][j]){
		cntot -= merge(j, n + j);
	}

	int ans = 0;
	ans = (cnt[R] - cntot) - (cnt[L-1] - cntl) + cntr;
	printf("%d\n", ans);
}


int main() {

	///freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &Q);

	for(int i = 0; i < n; i ++){
		for(int j = 1; j <= m; j ++) scanf("%d", col[j] + i);
	}

	prepare();

	int L, R;
	while(Q --){
		scanf("%d %d", &L, &R);
		query(L, R);
	}
}
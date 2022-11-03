#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 500 + 10;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int tot;
char s[MAXN][MAXN];
int id[MAXN][MAXN];
int size[MAXN * MAXN];

void BFS(int sx, int sy){
	static int que[MAXN * MAXN][2];
	size[++tot] = 1;
	id[sx][sy] = tot;
	que[0][0] = sx, que[0][1] = sy;
	for (int l = 0, r = 1; l < r; ++l){
		int x0 = que[l][0], y0 = que[l][1];
		for (int i = 0; i < 4; ++i){
			int x = x0 + d[i][0], y = y0 + d[i][1];
			if (s[x][y] == '.' && !id[x][y]){
				++size[tot];
				id[x][y] = tot;
				que[r][0] = x, que[r][1] = y;
				++r;
			}
		}
	}
//	printf("%d\n", size[tot]);
}

int sum;
int cnt[MAXN * MAXN];

void insert(int t){
//	printf("insert %d %d\n", t, cnt[t]);
	if (t == -1)
		++sum;
	else if ((cnt[t]++) == 0)
		sum += size[t];
//	printf("insert %d %d\n", t, cnt[t]);
}

void erase(int t){
//	printf("erase %d %d\n", t, cnt[t]);
	if (t == -1)
		--sum;
	else if ((--cnt[t]) == 0)
		sum -= size[t];
//	printf("erase %d %d\n", t, cnt[t]);
}

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i][j] == '.' && !id[i][j])
				BFS(i, j);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i][j] == 'X')
				id[i][j] = -1;

	int ans = 0;
	for (int i = K; i <= n; ++i){
		sum = 0;
		memset(cnt, 0, sizeof(cnt));

		int s0 = 0;
		for (int j = i - K + 1; j <= i; ++j){
			for (int k = 1; k <= K; ++k)
				insert(id[j][k]);
//			printf("== %d\n", sum);
			insert(id[j][0]);
			insert(id[j][K + 1]);
			insert(id[i - K][j - i + K]);
			insert(id[i + 1][j - i + K]);
//			printf("==== %d\n", sum);
			s0 += s[j][0] == 'X';
			s0 += s[j][K + 1] == 'X';
			s0 += s[i - K][j - i + K] == 'X';
			s0 += s[i + 1][j - i + K] == 'X';
		}
//		printf("%d %d %d %d\n", i, K, sum, s0);
		ans = max(ans, sum - s0);
		for (int j = K + 1; j <= n; ++j){
			erase(id[i - K][j - K]);
			insert(id[i - K][j]);
			erase(id[i + 1][j - K]);
			insert(id[i + 1][j]);

			s0 -= s[i - K][j - K] == 'X';
			s0 += s[i - K][j] == 'X';
			s0 -= s[i + 1][j - K] == 'X';
			s0 += s[i + 1][j] == 'X';
//			printf("sum:  %d %d %d %d\n", i, j, sum, s0);
			for (int k = i - K + 1; k <= i; ++k){
				erase(id[k][j - K - 1]);
				insert(id[k][j + 1]);
				s0 -= s[k][j - K - 1] == 'X';
				s0 += s[k][j - K] == 'X';
				s0 -= s[k][j] == 'X';
				s0 += s[k][j + 1] == 'X';
//				printf("%d %d\n", k, s0);
			}
//			printf("cnt[2] = %d\n", cnt[2]);
//			printf("sum:  %d %d %d %d\n", i, j, sum, s0);
			ans = max(ans, sum - s0);
		}
	}
	printf("%d\n", ans);
	return 0;
}
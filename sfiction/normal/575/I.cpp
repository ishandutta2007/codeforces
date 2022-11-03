#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXQ = 1E5 + 10, MAXN = 5E3 + 10;;

int n, m, Q;
int dir[MAXQ], x[MAXQ], y[MAXQ], len[MAXQ];
int ans[MAXQ];
int s1[MAXN][MAXN], s2[MAXN][MAXN << 1];

int query1(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i &= i - 1)
		for (int j = y; j > 0; j &= j - 1)
			ret += s1[i][j];
	return ret;
}

int query2(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i &= i - 1)
		for (int j = y; j > 0; j &= j - 1)
			ret += s2[i][j];
	return ret;
}

void update1(int x, int y, int c){
	x = max(x, 1), y = max(y, 1);
	for (int i = x; i <= n; i = (i | i - 1) + 1)
		for (int j = y; j <= n; j = (j | j - 1) + 1)
			s1[i][j] += c;
}

void update2(int x, int y, int c){
	x = max(x, 1), y = max(y, 1);
	for (int i = x; i <= n; i = (i | i - 1) + 1)
		for (int j = y; j <= m; j = (j | j - 1) + 1)
			s2[i][j] += c;
}

int main(){
	scanf("%d%d", &n, &Q);
	m = n << 1;
	for (int com, i = 0; i < Q; ++i){
		scanf("%d", &com);
		if (com == 1)
			scanf("%d%d%d%d", &dir[i], &x[i], &y[i], &len[i]);
		else{
			scanf("%d%d", &x[i], &y[i]);
			len[i] = -1;
		}
	}

	for (int i = 0; i < Q; ++i)
		if (len[i] == -1){
			ans[i] += query1(x[i], y[i]);
			ans[i] += query2(n + 1 - y[i], x[i] + y[i]);
		}
		else if (dir[i] == 1){
			update1(x[i], y[i], 1);
			update1(x[i], y[i] + len[i] + 1, -1);
			// x[i] + 1, y[i] + len
			// x[i] + len + 2, y[i] - 1
			update2(n + 1 - y[i] - len[i], x[i] + y[i] + len[i] + 1, -1);
			update2(n + 2 - y[i], x[i] + y[i] + len[i] + 1, 1);
		}
		else if (dir[i] == 4){
			update1(x[i] + 1, y[i] - len[i], -1);
			update1(x[i] + 1, y[i] + 1, 1);
			// x[i] - len, y[i]
			// x[i] + 1, y[i] - len - 1
			update2(n + 1 - y[i], x[i] + y[i] - len[i], 1);
			update2(n + 2 - y[i] + len[i], x[i] + y[i] - len[i], -1);
		}
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	for (int i = 0; i < Q; ++i)
		if (len[i] == -1){
			ans[i] += query1(x[i], y[i]);
			ans[i] += query2(x[i], n + y[i] - x[i]);
		}
		else if (dir[i] == 2){
			update1(x[i], y[i] + 1, -1);
			update1(x[i] + len[i] + 1, y[i] + 1, 1);
			// x[i], y[i] - len
			// x[i] + len + 1, y[i] + 1
			update2(x[i], n + y[i] - x[i] - len[i], 1);
			update2(x[i] + len[i] + 1, n + y[i] - x[i] - len[i], -1);
		}
		else if (dir[i] == 3){
			update1(x[i] - len[i], y[i], 1);
			update1(x[i] + 1, y[i], -1);
			// x[i] - len, y[i] + 1
			// x[i] + 1, y[i] + len + 2
			update2(x[i] - len[i], n + y[i] - x[i] + len[i] + 1, -1);
			update2(x[i] + 1, n + y[i] - x[i] + len[i] + 1, 1);
		}

	for (int i = 0; i < Q; ++i)
		if (len[i] == -1)
			printf("%d\n", ans[i]);
	return 0;
}
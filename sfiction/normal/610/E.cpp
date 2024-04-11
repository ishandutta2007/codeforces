#include <cstdio>
#include <cstring>

const int MAXN = 2E5 + 10, MAXK = 10;

int n, m, K;
char s1[MAXN];

int sym[MAXN << 2];
int s[MAXN << 2][MAXK][MAXK];
int L, R, C, D;

void pushUp(int u){
	int (&m)[MAXK][MAXK] = s[u];
	int (&l)[MAXK][MAXK] = s[u << 1], (&r)[MAXK][MAXK] = s[u << 1 | 1];
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j)
			m[i][j] = l[i][j] + r[i][j];
			
}

void pushDown(int u, int len){
	memset(s[u << 1], 0, sizeof(s[0]));
	s[u << 1][sym[u]][sym[u]] = len >> 1;
	memset(s[u << 1 | 1], 0, sizeof(s[0]));
	s[u << 1 | 1][sym[u]][sym[u]] = len + 1 >> 1;
	sym[u << 1] = sym[u << 1 | 1] = sym[u];
	sym[u] = -1;
}

void build(int u, int l, int r){
	if (l + 1 == r){
		memset(s[u], 0, sizeof(s[u]));
		s[u][s1[l]][s1[r]] = 1;
		sym[u] = s1[l];
//		printf("%d", sym[u]);
		return;
	}
	sym[u] = -1;
	int m = l + r >> 1;
	build(u << 1, l, m);
	build(u << 1 | 1 ,m ,r);
	pushUp(u);
}

void update(int u, int l, int r){
	if (l + 1 == r){
		memset(s[u], 0, sizeof(s[u]));
		s[u][C][D] = 1;
		sym[u] = C;
		return;
	}
	if (~sym[u])
		pushDown(u, r - l);
	int m = l + r >> 1;
	if (L < m)
		update(u << 1, l, m);
	else
		update(u << 1 | 1, m, r);
	pushUp(u);
}

void updateRange(int u, int l, int r){
	if (L <= l && r <= R){
		memset(s[u], 0, sizeof(s[u]));
		s[u][C][C] = r - l;
		sym[u] = C;
		return;
	}
	if (~sym[u])
		pushDown(u, r - l);
	int m = l + r >> 1;
	if (L < m)
		updateRange(u << 1, l, m);
	if (m < R)
		updateRange(u << 1 | 1, m, r);
	pushUp(u);
}

void query(int u, int l, int r){
	if (l + 1 == r){
		C = sym[u];
		return;
	}
	if (~sym[u])
		pushDown(u, r - l);
	int m = l + r >> 1;
	if (L < m)
		query(u << 1, l, m);
	else
		query(u << 1 | 1, m, r);
	pushUp(u);
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s", s1);

	if (n == 1){
		for (int t, i = 0; i < m; ++i){
			scanf("%d", &t);
			if (t == 1)
				scanf("%*d%*d%*s");
			else
				scanf("%*s"), puts("1");
		}
		return 0;
	}

	for (int i = 0; i < n; ++i)
		s1[i] -= 'a';
	build(1, 0, n - 1);
	sym[0] = s1[n - 1];
	char ts[MAXK + 1];
	for (int com, i = 0; i < m; ++i){
		scanf("%d", &com);
		if (com == 1){
			scanf("%d%d%s", &L, &R, ts);
			--L, --R, C = ts[0] -= 'a';
			if (L < R)
				updateRange(1, 0, n - 1);
			if (L > 0){
				--L, query(1, 0, n - 1), D = ts[0], update(1, 0, n - 1);
			}
			if (R < n - 1){
				if (R == n - 2)
					D = sym[0];
				else
					L = R + 1, query(1, 0, n - 1), D = C;
				L = R, C = ts[0], update(1, 0, n - 1);
			}
			else{
				sym[0] = ts[0];
			}
		}
		else{
			scanf("%s", ts);
			int ans = 0;
			for (int j = 0; j < K; ++j){
				ts[j] -= 'a';
				for (int k = 0; k <= j; ++k)
					ans += s[1][ts[j]][ts[k]];
			}
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}
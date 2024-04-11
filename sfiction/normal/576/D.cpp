#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAXN = 160, MAXM = 150 + 5;
const int INF = 1E9 + MAXN;

int n, m;

struct Edge{
	int u, v, d;

	bool operator<(const Edge &r)const{
		return d < r.d;
	}
}e[MAXM];

struct Matrix{
	bitset<MAXN> a[MAXN];
}A;

Matrix operator*(const Matrix &l, const Matrix &r){
	static Matrix t;
	Matrix ret;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			t.a[i][j] = r.a[j][i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret.a[i][j] = (l.a[i] & t.a[j]).any();
	return ret;
}

int cnt = 0;
bitset<MAXN> can[MAXN] = {1};

int dis[MAXN][MAXN];

Matrix matExp(Matrix A, int n){
	Matrix ret = A;
	for (--n; n; n >>= 1, A = A * A)
		if (n & 1)
			ret = ret * A;
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].d);
		--e[i].u;
		--e[i].v;
	}
	sort(e, e + m);
	e[m].u = e[m].v = n;
	e[m].d = e[m - 1].d + 1;
	int pre = 0, ans = INF;
	for (int k = 0; k <= m; ++k){
		if (e[k].d > pre){
			Matrix res = matExp(A, e[k].d - pre);
			pre = e[k].d;
			for (int i = 0; i < n; ++i)
				if (can[cnt][i])
					can[cnt + 1] |= res.a[i];
			++cnt;
			A.a[e[k].u][e[k].v] = 1;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					dis[i][j] = i == j ? 0 : A.a[i][j] ? 1 : INF;
			for (int l = 0; l < n; ++l)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
			for (int i = 0; i < n; ++i)
				if (can[cnt][i])
					ans = min(ans, e[k].d + dis[i][n - 1]);
		}
		else
			A.a[e[k].u][e[k].v] = 1;
	}
	if (ans == INF)
		puts("Impossible");
	else
		printf("%d\n", ans);
	return 0;
}
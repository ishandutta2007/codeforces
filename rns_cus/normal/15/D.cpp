///	Choe Kwang D

#include <bits/stdc++.h>
using namespace std;
#define N 1010

typedef long long LL;

multiset <LL> s;
multiset <LL> :: iterator it;

struct rectangle {
	LL s;
	pair <int, int> pos;
} sq[N*N];

bool operator < (rectangle a, rectangle b) {
	if (a.s != b.s) return (a.s < b.s);
	return (a.pos.first != b.pos.first) ? (a.pos.first < b.pos.first) : (a.pos.second < b.pos.second);
}

int n, m, a, b, pnt[N][N], ans[N*N];
LL x[N][N], mnc[N][N], mn[N][N], sumc[N][N], sum[N][N];
bool vis[N*N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%I64d", &x[i][j]);
	for (int i = 1; i <= n; i ++) {
		s.clear();
		for (int j = 1; j <= b; j ++) s.insert(x[i][j]);
		it = s.begin();
		mnc[i][1] = *it;
		for (int j = b + 1; j <= m; j ++) {
			it = s.find(x[i][j-b]);
			s.erase(it);
			s.insert(x[i][j]);
			it = s.begin();
			mnc[i][j-b+1] = *it;
		}
	}
	for (int j = 1; j <= m - b + 1; j ++) {
		s.clear();
		for (int i = 1; i <= a; i ++) s.insert(mnc[i][j]);
		it = s.begin();
		mn[1][j] = *it;
		for (int i = a + 1; i <= n; i ++) {
			it = s.find(mnc[i-a][j]);
			s.erase(it);
			s.insert(mnc[i][j]);
			it = s.begin();
			mn[i-a+1][j] = *it;
		}
	}

	for (int i = 1; i <= n; i ++) {
		sumc[i][1] = 0;
		for (int j = 1; j <= b; j ++) sumc[i][1] += x[i][j];
		for (int j = b + 1; j <= m; j ++) sumc[i][j-b+1] = sumc[i][j-b] - x[i][j-b] + x[i][j];
	}
	for (int j = 1; j <= m - b + 1; j ++) {
		sum[1][j] = 0;
		for (int i = 1; i <= a; i ++) sum[1][j] += sumc[i][j];
		for (int i = a + 1; i <= n; i ++) sum[i-a+1][j] = sum[i-a][j] - sumc[i-a][j] + sumc[i][j];
	}
	int runs = 0;
	for (int i = 1; i <= n - a + 1; i ++) {
		for (int j = 1; j <= m - b + 1; j ++) {
			sq[runs].s = sum[i][j] - a * b * mn[i][j];
			sq[runs].pos.first = i, sq[runs].pos.second = j;
			runs ++;
		}
	}
	sort(sq, sq + runs);
	memset(pnt, -1, sizeof pnt);
	for (int i = 0; i < runs; i ++) pnt[sq[i].pos.first][sq[i].pos.second] = i;
	int k = 0;
	for (int i = 0; i < runs; i ++) {
		if (vis[i]) continue;
		ans[k++] = i;
		int I = sq[i].pos.first, J = sq[i].pos.second;
		int stx = max(I - a + 1, 1), enx = min(I + a - 1, n - a + 1);
		int sty = max(J - b + 1, 1), eny = min(J + b - 1, m - b + 1);
		for (int ii = stx; ii <= enx; ii ++)
			for (int jj = sty; jj <= eny; jj ++) vis[pnt[ii][jj]] = 1;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i ++) {
		printf("%d %d %I64d\n", sq[ans[i]].pos.first, sq[ans[i]].pos.second, sq[ans[i]].s);
	}
	return 0;
}
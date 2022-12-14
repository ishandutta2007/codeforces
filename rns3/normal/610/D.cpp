#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
#define M 400010

typedef long long LL;
typedef pair <int, int> PII;

map <int, int> mpX, mpY;
int cntx, cnty, n, a[M], b[M], c[M], f[M], cnt, id[M];

int insertX(int x) {
	if (!mpX.count(x)) mpX[x] = cntx, a[cntx++] = x;
	return mpX[x];
}

int insertY(int y) {
	if (!mpY.count(y)) mpY[y] = cnty, b[cnty++] = y;
	return mpY[y];
}

LL ans;
vector <PII> vx[M], vy[M];

void simplize(vector <PII> &v) {
	sort(v.begin(), v.end());
	int N = 0, st = -INF, en = -INF;
	for (int j = 0; j < v.size(); j++) {
		PII p = v[j];
		if (en < p.first) {
			if (en != -INF) v[N++] = PII(st, en);
			st = p.first, en = p.second;
		}
		else {
			if (p.second > en) en = p.second;
		}
	}
	v[N++] = PII(st, en);
	v.resize(N);
	for (int i = 0; i < N; i++) ans += v[i].second - v[i].first + 1;
}

void add(int x, int val) {
	x = lower_bound(c, c + cntx, x) - c + 1;
	while (x <= cntx) {f[x] += val; x += (x & -x);}
}

int calc(int x) {
	int res = 0; while (x) {res += f[x]; x -= (x & -x);}
	return res;
}

bool cmp(int i, int j) {return b[i] < b[j];}

struct dat {
	int y, x, sign;
	dat (int y = 0, int x = 0, int sign = 0) : y(y), x(x), sign(sign) {}
	bool operator < (const dat &a) const {return (y < a.y);}
} p[M];

int main() {
	scanf("%d", &n);

	int x, y, xx, yy;

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		if (x == xx) {
			if (y > yy) swap(y, yy); int id = insertX(x); vx[id].push_back(PII(y, yy));
		}
		else {
			if (x > xx) swap(x, xx); int id = insertY(y); vy[id].push_back(PII(x, xx));
		}
	}
	for (int i = 0; i < cntx; i++) simplize(vx[i]);
	for (int i = 0; i < cnty; i++) simplize(vy[i]);

	for (int i = 0; i < cntx; i++) c[i] = a[i];
	sort(c, c + cntx);

	for (int i = 0; i < cntx; i++) {
		int id = lower_bound(c, c + cntx, a[i]) - c + 1;
		for (int j = 0; j < vx[i].size(); j++) {
			p[cnt++] = dat(vx[i][j].first - 1, id, 1);
			p[cnt++] = dat(vx[i][j].second, id, -1);
		}
	}

	for (int i = 0; i < cnty; i++) id[i] = i;

	sort(p, p + cnt); sort(id, id + cnty, cmp); sort(b, b + cnty);

	int last = 0;

	for (int i = 0; i < cnt; i++) {
		int en = upper_bound(b, b + cnty, p[i].y) - b - 1;
		for (int k = last; k <= en; k++) {
			for (int j = 0; j < vy[id[k]].size(); j++) {
				add(vy[id[k]][j].first, 1); add(vy[id[k]][j].second + 1, - 1);
			}
		}
		ans += p[i].sign * calc(p[i].x);
		if (last < en + 1) last = en + 1;
	}
	printf("%I64d\n", ans);
}
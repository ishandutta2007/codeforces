#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
#define M 100010
#define INF (1 << 30)
vector <PII> vx[M], vy[M];
vector <int> End[M];

PII b[M], r[M];
int px[M], py[M], f[M];

int n, m, nx, ny;

void clear() {
	for (int i = 0; i <= nx; i++) vx[i].clear();
	for (int i = 0; i <= ny; i++) vy[i].clear();
}

int get_pos(int bf, int x) {
	if (!bf) return lower_bound(py, py + ny, x) - py + 1;
	else return lower_bound(px, px + nx, x) - px + 1;
}

void resize(vector <PII> &v) {
	if (!v.size()) return;
	sort(v.begin(), v.end());
	int st = -INF, en = -INF, cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > en) {
			if (en != -INF) v[cnt++] = PII(st, en);
			st = v[i].first, en = v[i].second;
		}
		else {
			if (v[i].second > en) en = v[i].second;
		}
	}
	v[cnt++] = PII(st, en); v.resize(cnt);
}

void add(int x, int val) {for ( ; x <= ny; x += (x & -x)) f[x] += val;}
int calc(int x) {int rt = 0; for ( ; x; x -= (x & -x)) rt += f[x]; return rt;}

bool Find(int x, int st, int en) {
	for (int i = 1; i <= ny; i++) f[i] = 0;
	for (int i = 1; i <= nx; i++) End[i].clear();
	for (int i = st; i <= en; i++) {
		for (int j = 0; j < vy[i].size(); j++) {
			if (vy[i][j].first <= x && vy[i][j].second > x) {
				End[vy[i][j].second].push_back(i); add(i, 1);
			}
		}
	}
	for (int i = x + 1; i <= nx; i++) {
		for (int j = 0; j < vx[i].size(); j++) {
			int s = max(st, vx[i][j].first), e = min(en, vx[i][j].second);
			if (s < e) {
				if (calc(e) - calc(s - 1) > 1) return 1;
			}
		}
		for (int j = 0; j < End[i].size(); j++) add(End[i][j], -1);
	}
	return 0;
}

bool check(int t) {
	nx = 0, ny = 0;
	for (int i = 0; i < n; i++) px[nx++] = b[i].first, py[ny++] = b[i].second - 2 * t, py[ny++] = b[i].second + 2 * t;
	for (int i = 0; i < m; i++) py[ny++] = r[i].second, px[nx++] = r[i].first - 2 * t, px[nx++] = r[i].first + 2 * t;
	sort(px, px + nx); nx = unique(px, px + nx) - px;
	sort(py, py + ny); ny = unique(py, py + ny) - py;
	clear();
	for (int i = 0; i < n; i++) {
		int x = get_pos(1, b[i].first);
		int st = get_pos(0, b[i].second - 2 * t), en = get_pos(0, b[i].second + 2 * t);
		vx[x].push_back(PII(st, en));
	}
	for (int i = 0; i < m; i++) {
		int x = get_pos(0, r[i].second);
		int st = get_pos(1, r[i].first - 2 * t), en = get_pos(1, r[i].first + 2 * t + 1) - 1;
		if (st < en) vy[x].push_back(PII(st, en));
	}
	for (int i = 1; i <= nx; i++) resize(vx[i]);
	for (int i = 1; i <= ny; i++) resize(vy[i]);

	for (int i = 1; i <= nx; i++) {
		for (int j = 0; j < vx[i].size(); j++) {
			if (Find(i, vx[i][j].first, vx[i][j].second)) return 1;
		}
	}
	return 0;
}

int main() {
	int x, y;
	scanf("%d %d", &n, &m);
	if (n < 2 || m < 2) return puts("Poor Sereja!"), 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y); b[i] = PII(x + y, x - y);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y); r[i] = PII(x + y, x - y);
	}
	int l = 1, r = 1000000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == 1000000) puts("Poor Sereja!");
	else printf("%d\n", l);
}
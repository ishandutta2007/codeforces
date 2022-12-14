#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
#define M 200010
int vis[M];
int x[M], y[M], id[M], n, cnt;
PII p[M];

void init() {
	for (int i = 0; i < 310; i++) for (int j = 0; j < 310; j++) {
		vis[i*i+j*j] = 1; p[i*i+j*j] = PII(i, j);
	}
}

void get_sign(int *x) {
	for (int i = 1; i <= n; i++) p[i] = PII(x[i], i);
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	int d = 0;
	for (int i = 1; i < n; i += 2) {
		if (p[i].first == p[i+1].first) {
			x[p[i].second] = -x[p[i].second];
		}
		else {
			if (d <= 0) {
				x[p[i+1].second] = -x[p[i+1].second];
				d += (p[i].first - p[i+1].first);
			}
			else {
				d -= (p[i].first - p[i+1].first);
				x[p[i].second] = -x[p[i].second];
			}
		}
	}
	if (n & 1) {
		x[p[n].second] = -x[p[n].second];
	}
}

double ang[M];

bool cmp(int i, int j) {return ang[i] < ang[j];}

int main() {
	//freopen("G.in", "r", stdin); freopen("G.out", "w", stdout);
	init();
	scanf("%d", &n);
	int i, sum = 0;
	for (i = 1; i && cnt < n - 1; i++) {
		if (vis[i]) x[++cnt] = p[i].first, y[cnt] = p[i].second, sum += i;
	}
	int a, b, t = 0;
	for (int j = i; t < 2; j++) {
		if (vis[j]) {
			if (!t) a = j; else b = j; t++;
		}
	}
	int ok = 0;
	if ((sum + a) % 2 == 0) x[++cnt] = p[a].first, y[cnt] = p[a].second;
	else if ((sum + b) % 2 == 0) x[++cnt] = p[b].first, y[cnt] = p[b].second;
  else {
	x[++cnt] = p[a].first, y[cnt] = p[a].second;
		if (sum & 1) x[1] = p[b].first, y[1] = p[b].second;
		else x[3] = p[b].first, y[3] = p[b].second;
		ok = 1;
  }
	sum = 0;
	for (i = 1; i <= cnt; i++) sum += x[i];
	if (sum & 1) {
		if (!ok) swap(x[1], y[1]);
		else swap(x[4], y[4]);
	}

	get_sign(x);
	get_sign(y);
	for (int i = 1; i <= n; i++) ang[i] = atan2(y[i], x[i]);
	for (int i = 1; i <= n; i++) id[i] = i;

	sort(id + 1, id + n + 1, cmp);
	puts("YES");
	int tx = 0, ty = 0;
	for (int i = 1; i <= n; i++) {
		tx += x[id[i]], ty += y[id[i]];
		printf("%d %d\n", tx, ty);
	}
}
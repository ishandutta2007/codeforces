#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
#define N 303030

pair <int, int> p[N];
int n;
int pos[N], val[N], r[N], b[N];

char type[3];

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++) {
		scanf("%d %s", &x, type);
		if (type[0] == 'G') p[i] = make_pair(x, 0);
		else if (type[0] == 'R') p[i] = make_pair(x, 1);
		else if (type[0] == 'B') p[i] = make_pair(x, 2);
	}
	bool left_bad = 0, right_bad = 0;
	if (p[1].second) {
		left_bad = 1;
		for (int i = n + 1; i >= 2; i --) p[i] = p[i-1];
		p[1].second = 0;
		n ++;
	}
	if (p[n].second) {
		right_bad = 1;
		p[n+1] = p[n], n ++, p[n].second = 0;
	}
	int e = 0;
	for (int i = 1; i <= n; i ++) if (!p[i].second) pos[e] = i, val[e++] = p[i].first;
	e --;
	if (left_bad && right_bad && e == 1) {
		long long ans = 0;
		int mnr = INF, mxr = -INF, mnb = INF, mxb = -INF;
		for (int i = 2; i < n; i ++) {
			if (p[i].second == 1) mnr = min(mnr, p[i].first), mxr = max(mxr, p[i].first);
			else mnb = min(mnb, p[i].first), mxb = max(mxb, p[i].first);
		}
		ans += max(0, mxr - mnr);
		ans += max(0, mxb - mnb);
		printf("%I64d\n", ans);
		return 0;
	}
	long long ans = 0;
	for (int k = 1; k <= e; k ++) {
		int cnt = 0;
		int le = val[k-1], ri = val[k];
		if (pos[k-1] == pos[k] - 1) {
			ans += ri - le;
			continue;
		}
		int R = 0, B = 0;
		for (int i = pos[k-1] + 1; i < pos[k]; i ++) {
			if (p[i].second == 1) r[++R] = p[i].first;
			else b[++B] = p[i].first;
		}
		if (left_bad && k == 1) {
			if (R) ans += val[1] - r[1];
			if (B) ans += val[1] - b[1];
			continue;
		}
		if (right_bad && k == e) {
			if (R) ans += r[R] - val[k-1];
			if (B) ans += b[B] - val[k-1];
			continue;
		}
		if (!R && !B) {
			ans += val[k] - val[k-1];
			continue;
		}
		long long now1 = 3ll * (val[k] - val[k-1]);
		int tmp = 0;
		r[0] = val[k-1], r[R+1] = val[k];
		for (int i = 0; i <= R; i ++) tmp = max(tmp, r[i+1] - r[i]);
		now1 -= tmp;
		tmp = 0;
		b[0] = val[k-1], b[B+1] = val[k];
		for (int i = 0; i <= B; i ++) tmp = max(tmp, b[i+1] - b[i]);
		now1 -= tmp;

		long long now2 = 2 * (val[k] - val[k-1]);

		ans += min(now1, now2);
	}
	printf("%I64d\n", ans);

	return 0;
}
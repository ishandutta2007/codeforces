#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 10000000;
struct segnode {
	int s, e, m, v;
	segnode *l, *r;
	segnode(int _s, int _e) {
		s = _s, e = _e, m = (s + e) / 2, v = 0;
		if (s != e) {
			l = new segnode(s, m);
			r = new segnode(m + 1, e);
		}
	}
	void update(int i, int newv) {
		if (s == e) {
			v = newv;
			return;
		}
		if (i > m) r -> update(i, newv);
		else l -> update(i, newv);
		v = min(l -> v, r -> v);
	}
	int query(int a, int b) {
		if (a == s && b == e) return v;
		if (a > m) return r -> query(a, b);
		if (b <= m) return l -> query(a, b);
		return min(l -> query(a, m), r -> query(m + 1, b));
	}
} *r1, *r2;
int main() {
	int n;
	scanf("%d", &n);
	int arr[3 * n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		arr[2 * n + i] = arr[n + i] = arr[i];
	}
	r1 = new segnode(0, 3 * n - 1);
	for (int i = 0; i < 3 * n; ++i) r1 -> update(i, arr[i]);
	r2 = new segnode(0, 2 * n - 2);
	for (int i = 0; i < 2 * n - 1; ++i) {
		int v = arr[i] / 2 - 1;
		if (arr[i] % 2) v += 1;
		if (r1 -> query(i + 1, 3 * n - 1) > v) r2 -> update(i, INF);
		else {
			int l = i + 1, u = 3 * n - 1, m;
			while (l != u) {
				m = (l + u) / 2;
				if (r1 -> query(i + 1, m) > v) l = m + 1;
				else u = m;
			}
			r2 -> update(i, l);
		}
	}
	for (int i = 0; i < n; ++i) {
		int ans = r2 -> query(i, i + n - 1);
		if (ans == INF) printf("-1 ");
		else printf("%d ", ans - i);
	}
	return 0;
}
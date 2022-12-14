#include <cstdio>
#include <algorithm>
#define m (s + e) / 2
using namespace std;
struct segnode {
	int s, e, v;
	segnode *l, *r;
	segnode(int _s, int _e, int k[]) {
		s = _s;
		e = _e;
		if (s != e) {
			l = new segnode(s, m, k);
			r = new segnode(m + 1, e, k);
			v = max(l -> v, r -> v);
		} else v = k[s];
	}
	int query(int a, int b) {
		if (a == s && b == e) return v;
		if (a > m) return r -> query(a, b);
		if (b <= m) return l -> query(a, b);
		return max(l -> query(a, m), r -> query(m + 1, b));
	}
};
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int N, M, P, S;
		scanf("%d", &N);
		int A[N], pow[N];
		fill_n(pow, N, 0);
		for (int j = 0; j < N; ++j) scanf("%d", &A[j]);
		scanf("%d", &M);
		for (int j = 0; j < M; ++j) {
			scanf("%d %d", &P, &S);
			pow[S - 1] = max(pow[S - 1], P);
		}
		segnode mon(0, N - 1, A), her(0, N - 1, pow);
		int en = 0, l, u, midval, ans = 0;
		while (en != N) {
			l = 0, u = N - en;
			while (l != u) {
				midval = (l + u) / 2 + 1;
				if (midval == 0) l = midval;
				else if (mon.query(en, en + midval - 1) > her.query(midval - 1, N - 1)) u = midval - 1;
				else l = midval;
			}
			if (l == 0) {
				printf("-1\n");
				goto hell;
			}
			en += l, ++ans;
		}
		printf("%d\n", ans);
		hell:;
	}
	return 0;
}
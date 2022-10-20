#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 10005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, fa[N], q[N], head, tail;
vector<int> tree[N];

inline int Query(int tot) {
	printf("? %d", tot);
	for (int i = 1; i <= tot; ++i) {
		printf(" %d", q[i]);
	}
	printf("\n");
	fflush(stdout);
	int ret; read(ret);
	return ret;
}

void solve() {
	read(n);
	for (int i = 1, u, v; i < n; ++i) {
		read(u); read(v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	q[head = tail = 1] = 1;
	while (head <= tail) {
		int u = q[head++];
		for (auto v : tree[u]) {
			if (v == fa[u]) continue;
			fa[v] = u;
			q[++tail] = v;
		}
	}
	int mx = Query(tail);
	int L = 2, R = tail - 1, ans = tail;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (Query(mid) == mx) {
			ans = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
 	}
 	printf("! %d %d\n", q[ans], fa[q[ans]]);
 	fflush(stdout);
}

int main() {
	solve();
	return 0;
}
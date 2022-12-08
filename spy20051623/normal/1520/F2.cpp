#include <bits/stdc++.h>

using namespace std;

int d[200005];
int n;
map<pair<int, int>, int> rev;

int lowbit(int x) {
	return x & -x;
}

void add(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		d[i] += k;
	}
}

int sum(int x) {
	int r = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		r += d[i];
	}
	return r;
}

int ask(int l, int r) {
	if (rev.find(make_pair(l, r)) != rev.end())
		return rev[make_pair(l, r)] + sum(r) - sum(l - 1);
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	rev[make_pair(l, r)] = res;
	return res;
}

void ans(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d%d", &n, &t);
	while (t--) {
		int l = 1;
		int r = n;
		int k;
		scanf("%d", &k);
		while (r != l) {
			int m = (l + r) >> 1;
			int p = ask(l, m);
			if ((m - l + 1) - p < k) {
				k -= (m - l + 1) - p;
				l = m + 1;
			} else {
				r = m;
			}
		}
		ans(l);
		add(l, 1);
	}
	return 0;
}
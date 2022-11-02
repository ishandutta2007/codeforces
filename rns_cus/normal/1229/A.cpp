#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, vis[N];
typedef long long ll;
typedef pair <ll, int> pii;

pii p[N];
vector <ll> vec;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%I64d", &p[i].first);
	for (int i = 0; i < n; i ++) scanf("%d", &p[i].second);
	sort(p, p + n);
	ll ans = 0;
	for (int i = n - 1, j = n - 1; ~i; i = j) {
		while (~j && p[j].first == p[i].first) j --;
		if (i - j > 1) {
			vec.push_back(p[i].first);
			while (i > j) ans += p[i].second, i --;
		}
		else {
			bool fg = 0;
			for (auto x : vec) if ((p[i].first & x) == p[i].first) fg = 1;
			if (fg) ans += p[i].second;
		}
	}

	printf("%I64d\n", ans);

	return 0;
}
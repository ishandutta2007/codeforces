#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t, n;
LL a[N], b[N];

struct Item {
	LL x, y, id;
	bool operator < (const Item & o) const {
		return x > o.x;
	}
};


int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
		LL sum = 0;
		for (int i = 1; i <= n; i ++) sum += a[i];
		if (sum % n) {
			printf("-1\n"); continue;
		}

		vector< pair< pair<LL,LL>,LL >  > ans;
		for (int i = 2; i <= n; i ++) {
			if (a[i] % i == 0) {
				ans.push_back(make_pair(make_pair(i, 1), a[i] / i));
			} else {
				int need = i - a[i] % i;
				ans.push_back(make_pair(make_pair(1, i), need));
				a[i] += need;
				ans.push_back(make_pair(make_pair(i, 1), a[i] / i));
			}
		}
		for (int i = 2; i <= n; i ++) {
			ans.push_back(make_pair(make_pair(1, i), sum / n));
		}
		printf("%d\n", ans.size());
		for (auto p: ans) {
			printf("%lld %lld %lld\n", p.first.first, p.first.second, p.second);
		}

	}
}
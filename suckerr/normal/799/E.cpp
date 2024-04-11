#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
const long long INF = 1e9 + 7;

int n, m, k, cost[N], mask[N];
vector<int> like[4];
long long minp = 0;
multiset<int> s, taken;

bool maintain(int num, int relax = 0) {
	for (int i = 0; i < relax; i++) {
		auto it = taken.end();
		if (it != taken.begin()) {
			--it;
			minp -= *it;
			s.insert(*it);
			taken.erase(it);
		}
	}
	if (num < 0) return false;
	while (s.size() && taken.size() < num) {
		auto it = s.begin();
		minp += *it;
		taken.insert(*it);
		s.erase(it);
	}
	while (taken.size() && taken.size() > num) {
		auto it = taken.end();
		--it;
		minp -= *it;
		s.insert(*it);
		taken.erase(it);
	}
	return taken.size() == num;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
	}
	for (int i = 0; i < 2; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int x; scanf("%d", &x);
			--x;
			mask[x] |= (1 << i);
		}
	}
	for (int i = 0; i < n; i++) {
		like[mask[i]].push_back(cost[i]);
	}
	if (like[1].size() + like[3].size() < k || like[2].size() + like[3].size() < k ||
		2 * k - min(k, (int)like[3].size()) > m) {
		puts("-1");
		return 0;
	}
	while (like[1].size() < k) like[1].push_back(INF);
	while (like[2].size() < k) like[2].push_back(INF);
	for (int i = 0; i < 4; i++) {
		sort(like[i].begin(), like[i].end());
	}
	long long ans = (1LL << 60), cur = 0;
	for (int i = 0; i < k; i++) {
		cur += like[1][i];
		cur += like[2][i];
	}
	for (int i = k; i < like[1].size(); i++) s.insert(like[1][i]);
	for (int i = k; i < like[2].size(); i++) s.insert(like[2][i]);
	for (auto t : like[0]) s.insert(t);
	if (maintain(m - 2 * k)) {
		ans = min(ans, cur + minp);
	}
	// cout << ans << endl;
	for (int i = 1; i <= like[3].size() && i <= m; i++) {
		cur += like[3][i - 1];
		if (i <= k) {
			cur -= like[1][k - i]; s.insert(like[1][k - i]);
			cur -= like[2][k - i]; s.insert(like[2][k - i]);
		}
		if (maintain(m - i - (2 * k - 2 * min(k, i)), 2)) {
			ans = min(ans, cur + minp);
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> v;
	set<int> s;
	map<int, int> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		if (p > 0) {
			if (m[p] != 0) {
				printf("-1\n");
				return 0;
			} else {
				++m[p];
				s.insert(p);
				++cnt;
			}
		} else {
			if (m[-p] != 1) {
				printf("-1\n");
				return 0;
			} else {
				++m[-p];
				s.erase(-p);
				++cnt;
			}
		}
		if (s.empty()) {
			s.clear();
			m.clear();
			v.push_back(cnt);
			cnt = 0;
		}
	}
	if (!s.empty()) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", (int) v.size());
	for (auto &i:v)printf("%d ", i);
	return 0;
}
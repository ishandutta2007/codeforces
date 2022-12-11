#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 100010;

int a[NMAX], b[NMAX];
vector<int> maxWS[NMAX];

ll rngval;

ll getRNG() {
	rngval = (rngval * 37 + 10007) % 1000000007;
	return rngval;
}

struct Monoqueue {
	deque<int> yeet;
	void addValue(int x) {
		while (!yeet.empty() && yeet.back() < x) yeet.pop_back();
		yeet.push_back(x);
	}
	void removeValue(int x) {
		if (!yeet.empty() && yeet.front() == x) yeet.pop_front();
	}
	int getMax() {
		return yeet.front();
	}
};

int main() {
	int n, d; scanf("%d %d %lld", &n, &d, &rngval);
	for (int i = 0; i < n; ++i) a[i] = i + 1;
	for (int i = 0; i < n; ++i) swap(a[i], a[getRNG() % (i + 1)]);
	for (int i = 0; i < d; ++i) b[i] = 1;
	for (int i = 0; i < n; ++i) swap(b[i], b[getRNG() % (i + 1)]);
	vector<pair<int, int>> windows;
	for (int i = 0; i < n; ++i) {
		if (b[i] == 1) {
			if (windows.empty() || windows.back().second < i - 1) windows.emplace_back(i, i);
			else ++windows.back().second;
		}
	}
	vector<int> sizeToCompute;
	for (auto s_e : windows) sizeToCompute.push_back(s_e.second - s_e.first + 1);
	for (int sz : sizeToCompute) {
		if (!maxWS[sz].empty()) continue;
		maxWS[sz] = vector<int>(n);
		Monoqueue keso;
		for (int i = 0; i < n; ++i) {
			keso.addValue(a[i]);
			if (i >= sz) keso.removeValue(a[i - sz]);
			maxWS[sz][i] = keso.getMax();
		}
//		printf("ws %d:\n", sz);
//		for (int i = 0; i < n; ++i) printf("%d ", maxWS[sz][i]);
	}
	vector<int> ans(n);
	for (auto s_e : windows) {
		int ws = s_e.second - s_e.first + 1;
		for (int i = s_e.first; i < n; ++i) ans[i] = max(ans[i], maxWS[ws][i - s_e.first]);
	}
	for (int x : ans) printf("%d\n", x);
	return 0;
}
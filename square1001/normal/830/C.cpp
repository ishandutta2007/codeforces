#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct query { long long l, r, x; };
int n, a[109]; long long m;
int main() {
	cin >> n >> m;
	vector<query> v; vector<long long> cp = { 1LL << 60 };
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int pr = sqrt(a[i]);
		for (int j = 1; j < pr; j++) {
			v.push_back(query{ j, j + 1, (a[i] + j - 1) / j });
			cp.push_back(j);
		}
		cp.push_back(pr);
		int r = (a[i] + pr - 1) / pr, ptr = pr;
		for (int j = r; j > 1; j--) {
			v.push_back(query{ ptr, (a[i] + j - 2) / (j - 1), j });
			ptr = v.back().r; cp.push_back(ptr);
		}
		v.push_back(query{ ptr, 1LL << 60, 1 });
	}
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	vector<long long> sum(cp.size());
	for (query i : v) {
		int pl = lower_bound(cp.begin(), cp.end(), i.l) - cp.begin();
		int pr = lower_bound(cp.begin(), cp.end(), i.r) - cp.begin();
		sum[pl] += i.x; sum[pr] -= i.x;
	}
	for (int i = 1; i < cp.size(); i++) sum[i] += sum[i - 1];
	long long ret = 0;
	for (int i = 0; i < cp.size() - 1; i++) {
		long long r = min(cp[i + 1] - 1, (m + sum[0]) / sum[i]);
		if (cp[i] <= r) ret = max(ret, r);
	}
	cout << ret << endl;
	return 0;
}
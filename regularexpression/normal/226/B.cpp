#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>
#include <deque>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<long long> pref(n + 1, 0);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	vector<long long> ans(n + 1, 0);
	for (int k = 1; k <= n; ++k) {
		queue<int> q;
		q.push(1);
		int i = n - 1;
		int up = (n + k - 1) / k;
		while (i > 0) {
			int h = q.front();
			q.pop();
			int p = max(0, i - k);
			ans[k] += (pref[i] - pref[p]) * h;
			for (int j = 0; j < k && q.size() < up; ++j)
				q.push(h + 1);
			i = p;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		cout << ans[min(k, n)] << " ";
	}
	return 0;
}
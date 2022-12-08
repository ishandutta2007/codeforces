#include <bits/stdc++.h>
using namespace std;
bool h[100005];
vector<int> pr;
map<int, int> m;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, i, j, k;
	h[0] = h[1] = 1;
	for (i = 2; i <= 100000; ++i) {
		if (!h[i]) {
			pr.push_back(i);
			for (j = i; j <= 100000; j += i) {
				h[j] = 1;
			}
		}
	}
	cin >> t;
	pair<int, int> maxm;
	while (t--) {
		cin >> n;
		k = n;
		m.clear();
		for (i = 0; i < pr.size(); ++i) {
			if (k % pr[i] == 0) {
				while (k % pr[i] == 0) {
					++m[pr[i]];
					k /= pr[i];
				}
			}
		}
		maxm = {1, 1};
		for (auto pi : m) {
			if (pi.second > maxm.second)
				maxm = pi;
		}
		cout << maxm.second << endl;
		for (i = 0; i < maxm.second - 1; ++i)
			cout << maxm.first << ' ';
		while (maxm.second > 1) {
			n /= maxm.first;
			--maxm.second;
		}
		cout << n << endl;
	}
	return 0;
}
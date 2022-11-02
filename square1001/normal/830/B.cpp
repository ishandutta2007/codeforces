#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a; vector<int> bit;
void add(int i) {
	for (int p = i + 1; p <= n * 2; p += p & (-p)) {
		bit[p]++;
	}
}
int sum(int i) {
	int ret = 0;
	for (int p = i; p >= 1; p -= p & (-p)) {
		ret += bit[p];
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<vector<int> > v(100000);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[--a].push_back(i);
	}
	int ptr = 0, rem = n; long long ret = 0;
	bit.resize(n * 2 + 1);
	for (int i = 0; i < 100000; i++) {
		if (v[i].size()) {
			int r = 0, pr = 0, pl = 0, pidx = ptr - sum(ptr);
			for (int j : v[i]) {
				int px = (j < ptr ? j + n : j), idx = px - sum(px);
				r = max(r, idx - pidx);
				pr = max(pr, px - ptr);
			}
			ret += r + 1;
			ptr = (ptr + pr + 1) % n;
			rem -= v[i].size();
			for (int j : v[i]) add(j), add(j + n);
		}
	}
	cout << ret << endl;
	return 0;
}
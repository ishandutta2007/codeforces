#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, k;
	cin >> n >> k;

	vector<vector<int> > a(n, vector<int>(n, 0));
	vector<string> res(n, string(n, 'M'));

	vector<tuple<int,int,int> > vec;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++) {
			cin >> a[i][j];
			vec.emplace_back(a[i][j], i, j);
		}

	sort(vec.begin(), vec.end(), greater<>());

	auto [v,x,y] = vec[0];
	int L1 = x + y - k, R1 = x + y + k;
	int L2 = x - y - k, R2 = x - y + k;

	auto in = [&](int x, int y) {
		return x+y<=R1 && x+y >= L1 && x-y<=R2 && x-y>=L2;
	};
	vec.erase(vec.begin());
	for (auto [v, x, y]: vec) {
		if (not in(x, y)) res[x][y] = 'G';
		else {
			L1 = max(L1, x + y - k);
			R1 = min(R1, x + y + k);
			L2 = max(L2, x - y - k);
			R2 = min(R2, x - y + k);
		}
	}
	for (auto x: res) cout << x << "\n";

}
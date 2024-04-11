#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<2; i++) {
		int n;
		cin >> n;
		while (n--) {
			int x, y;
			cin >> x >> y;
			m[x] = max(m[x], y);
		}
	}

	long long z = 0;

	for (auto p : m)
		z += p.second;

	cout << z;
}
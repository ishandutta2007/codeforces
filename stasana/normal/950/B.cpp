#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	start();

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
	}

	int res = 1, yk1 = 1, yk2 = 1, s1 = a[0], s2 = b[0];

	while (yk1 < n && yk2 < m) {
		if (s1 == s2) {
			s1 = a[yk1++];
			s2 = b[yk2++];
			++res;
		}
		else if (s1 < s2) {
			s1 += a[yk1++];
		}
		else {
			s2 += b[yk2++];
		}
	}
	cout << res;
	return 0;
}
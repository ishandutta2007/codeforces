#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> d(N, inf), c(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		d[a] = min(d[a], (b - a + N) % N);
		++c[a];
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		long long x = 0;
		for (int j = 0; j < N; ++j) {
			if (c[j] == 0) continue;
			long long t = (j - i + N) % N + d[j] + (c[j] - 1) * N;
			x = max(x, t);
		}
		cout << x;
	}
	cout << endl;
	return 0;
}
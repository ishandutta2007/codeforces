#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int d, m;
		cin >> d >> m;
		int b = 0;
		while ((1 << b) <= d) ++b;
		vector<int> seq(b);
		for (int i = 0; i < b - 1; ++i) {
			seq[i] = (1 << i);
		}
		seq[b - 1] = d - (1 << (b - 1)) + 1;
		int ans = 1;
		for (int i = 0; i < b; ++i) {
			ans = 1LL * ans * (seq[i] + 1) % m;
		}
		cout << (ans + m - 1) % m << endl;
	}
	return 0;
}
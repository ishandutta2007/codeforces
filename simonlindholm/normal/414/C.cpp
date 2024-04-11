#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> inv[2];

vector<int> build(int n) {
	if (n == 0) {
		int el;
		cin >> el;
		return vector<int>(1, el);
	}
	else {
		vector<int> lnums = build(n-1);
		vector<int> rnums = build(n-1);
		int sz = (int)rnums.size();
		vector<int> nums(sz*2);
		std::merge(
				lnums.begin(), lnums.end(),
				rnums.begin(), rnums.end(),
				nums.begin());
		for (int c = 0; c < 2; ++c) {
			int i = 0;
			for (int j = 0; j < sz; ++j) {
				while (i < sz && lnums[i] <= rnums[j])
					++i;
				inv[c][n-1] += sz - i;
			}
			lnums.swap(rnums);
		}
		return nums;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int c = 0; c < 2; ++c)
		inv[c].assign(N, 0);
	build(N);
	int M;
	cin >> M;
	vector<int> states(N, 0);
	for (int q = 0; q < M; ++q) {
		int qi;
		cin >> qi;
		for (int i = 0; i < qi; ++i)
			states[i] ^= 1;
		long long res = 0;
		for (int i = 0; i < N; ++i)
			res += inv[states[i]][i];
		cout << res << '\n';
	}

	return 0;
}
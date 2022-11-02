#include <ctime>
#include <vector>
#include <iostream>
using namespace std;
vector<int> search(int n) {
	int u = 1;
	while (u <= n) u *= 2;
	vector<int> seq;
	for (int i = 1; i <= u / 2; ++i) {
		int x = u - i - 1;
		if (x > n) x -= u / 2;
		seq.push_back(x);
	}
	vector<int> res;
	if (n != u / 2) res = search(n - u / 2);
	seq.insert(seq.end(), res.begin(), res.end());
	return seq;
}
unsigned cur = 123456789;
unsigned xorshift32() {
	cur ^= cur << 13;
	cur ^= cur >> 17;
	cur ^= cur << 5;
	return cur;
}
int main() {
	int N;
	cin >> N;
	if (N % 2 == 1) {
		cout << "NO" << endl;
	}
	else {
		vector<int> res = search(N);
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << res[i];
		}
		cout << endl;
	}
	bool found = false;
	int loop = 0;
	while (clock() < CLOCKS_PER_SEC * 1.8) {
		vector<bool> used(N, false);
		vector<int> seq;
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < N * 10; ++j) {
				int u = xorshift32() % N;
				if (used[u] || (i & (u + 1)) == 0 || i == u + 1) continue;
				used[u] = true;
				seq.push_back(u + 1);
				break;
			}
			if (seq.size() != i) break;
		}
		if (seq.size() == N) {
			found = true;
			cout << "YES" << endl;
			for (int i = 0; i < N; ++i) {
				if (i) cout << ' ';
				cout << seq[i];
			}
			cout << endl;
			break;
		}
	}
	if (!found) {
		cout << "NO" << endl;
	}
	return 0;
}
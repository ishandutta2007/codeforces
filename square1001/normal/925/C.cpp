#include <vector>
#include <iostream>
using namespace std;
const int bits = 61;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		while ((1LL << (B[i] + 1)) <= A[i]) ++B[i];
	}
	vector<vector<long long> > G(bits);
	for (int i = 0; i < N; ++i) {
		G[B[i]].push_back(A[i]);
	}
	long long cur = 0;
	vector<long long> seq;
	for (int i = 0; i < N; ++i) {
		bool found = false;
		for (int j = 0; j < bits; ++j) {
			if (!((cur >> j) & 1) && !G[j].empty()) {
				found = true;
				seq.push_back(G[j].back());
				cur ^= seq.back();
				G[j].pop_back();
				break;
			}
		}
		if (!found) break;
	}
	if (seq.size() == N) {
		cout << "Yes" << endl;
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << seq[i];
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
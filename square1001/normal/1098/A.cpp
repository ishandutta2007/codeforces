#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 1; i < N; ++i) {
		cin >> P[i]; --P[i];
	}
	vector<int> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	vector<int> positive;
	for (int i = 1; i < N; ++i) {
		if (S[i] >= 0) positive.push_back(i);
	}
	for (int i = 0; i < N; ++i) {
		if (S[i] == -1) {
			S[i] = S[P[i]];
		}
	}
	bool ok = true;
	for (int i = 1; i < N; ++i) {
		if (S[P[i]] > S[i]) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		for (int i : positive) {
			S[P[i]] = 1 << 30;
		}
		for (int i : positive) {
			S[P[i]] = min(S[P[i]], S[i]);
		}
		long long ans = S[0];
		for (int i = 1; i < N; ++i) {
			ans += S[i] - S[P[i]];
		}
		cout << ans << endl;
	}
	return 0;
}
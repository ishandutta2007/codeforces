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
	int N, M;
	cin >> N >> M;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> topic(N);
	for (int i = 0; i < N; ++i) {
		cin >> topic[i];
	}
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		for (int j : G[i]) {
			if (topic[i] == topic[j]) {
				ok = false;
			}
		}
	}
	if (ok) {
		for (int i = 0; i < N; ++i) {
			vector<int> seq;
			for (int j : G[i]) {
				seq.push_back(topic[j]);
			}
			sort(seq.begin(), seq.end());
			seq.erase(unique(seq.begin(), seq.end()), seq.end());
			int cnt = 0;
			for (int j = 0; j < seq.size(); ++j) {
				if (seq[j] < topic[i]) ++cnt;
			}
			if (cnt < topic[i] - 1) {
				ok = false;
			}
		}
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		vector<int> perm(N);
		for (int i = 0; i < N; ++i) {
			perm[i] = i;
		}
		sort(perm.begin(), perm.end(), [&](int i, int j) { return topic[i] < topic[j]; });
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << perm[i] + 1;
		}
		cout << endl;
	}
	return 0;
}
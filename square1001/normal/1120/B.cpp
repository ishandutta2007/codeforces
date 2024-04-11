#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; string S, T;
	cin >> N >> S >> T;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		A[i] = int(S[i] - '0');
		B[i] = int(T[i] - '0');
	}
	vector<int> V = A;
	vector<int> ops(N - 1);
	long long sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		ops[i] = B[i] - V[i];
		V[i] += ops[i];
		V[i + 1] += ops[i];
		sum += (ops[i] > 0 ? ops[i] : -ops[i]);
	}
	if (V[N - 1] != B[N - 1]) {
		cout << -1 << '\n';
	}
	else {
		V = A;
		function<bool(int)> canmove = [&](int pos) {
			if (pos < 0 || pos >= N - 1) return false;
			if (ops[pos] > 0 && (V[pos] != 9 && V[pos + 1] != 9)) return true;
			if (ops[pos] < 0 && (V[pos] != (pos > 0 ? 0 : 1) && V[pos + 1] != 0)) return true;
			return false;
		};
		set<int> s;
		for (int i = 0; i < N - 1; ++i) {
			if (canmove(i)) s.insert(i);
		}
		vector<pair<int, int> > seq;
		int cnt = 0;
		while (!s.empty() && cnt++ < 100000) {
			int u = *s.begin();
			seq.push_back(make_pair(u, ops[u] > 0 ? 1 : -1));
			if (ops[u] > 0) ++V[u], ++V[u + 1], --ops[u];
			if (ops[u] < 0) --V[u], --V[u + 1], ++ops[u];
			s.erase(u - 1);
			s.erase(u);
			s.erase(u + 1);
			for (int i = u - 1; i <= u + 1; ++i) {
				if (canmove(i)) s.insert(i);
			}
		}
		cout << sum << '\n';
		for (pair<int, int> i : seq) {
			cout << i.first + 1 << ' ' << i.second << '\n';
		}
	}
	return 0;
}
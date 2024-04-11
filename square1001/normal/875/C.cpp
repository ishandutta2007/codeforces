#include <vector>
#include <iostream>
#include <functional>
using namespace std;
struct edge {
	int to, tp; // tp <- (0, 1), excludes edge color "tp --> (tp xor 1)"
	edge() : to(-1), tp(-1) {};
	edge(int to_, int tp_) : to(to_), tp(tp_) {};
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> s(N);
	vector<vector<int> > v(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		v[i].resize(s[i]);
		for (int j = 0; j < s[i]; j++) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	vector<int> col(M, -1);
	vector<vector<edge> > G(M);
	bool answer = true;
	for (int i = 0; i < N - 1; i++) {
		bool flag = false;
		for (int j = 0; j < s[i] && j < s[i + 1]; j++) {
			if (v[i][j] != v[i + 1][j]) {
				flag = true;
				if (v[i][j] > v[i + 1][j]) {
					if (col[v[i][j]] == -1) {
						col[v[i][j]] = 0;
					}
					if (col[v[i + 1][j]] == -1) {
						col[v[i + 1][j]] = 1;
					}
					if (col[v[i][j]] != 0 || col[v[i + 1][j]] != 1) {
						answer = false;
					}
				}
				else {
					G[v[i][j]].push_back(edge(v[i + 1][j], 1));
					G[v[i + 1][j]].push_back(edge(v[i][j], 0));
				}
				break;
			}
		}
		if (!flag && s[i] > s[i + 1]) {
			answer = false;
		}
	}
	function<bool(int)> check = [&](int pos) {
		for (edge e : G[pos]) {
			if (e.tp != col[pos]) continue;
			if ((e.tp ^ 1) == col[e.to]) return false;
			if (col[e.to] == -1) {
				col[e.to] = e.tp;
				if (!check(e.to)) return false;
			}
		}
		return true;
	};
	vector<int> first_col = col;
	for (int i = 0; i < M; i++) {
		if (first_col[i] != -1) {
			bool res = check(i);
			answer = answer && res;
		}
	}
	if (!answer) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += (col[i] == 0);
		}
		cout << cnt << '\n';
		for (int i = 0; i < M; i++) {
			if (col[i] != 0) continue;
			cout << i + 1;
			cout << (--cnt == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
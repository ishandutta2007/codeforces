#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> val(N);
	for (int i = 0; i < N; ++i) {
		cin >> val[i];
		if (val[i] >= 0) val[i] %= 2520;
		else val[i] = (2520 - (-val[i]) % 2520) % 2520;
	}
	vector<int> deg(N); vector<vector<int> > G(N);
	for (int i = 0; i < N; ++i) {
		cin >> deg[i];
		G[i].resize(deg[i]);
		for (int j = 0; j < deg[i]; ++j) cin >> G[i][j], --G[i][j];
	}
	vector<int> state(N * 2520, -1);
	vector<bool> flag(N, false);
	for (int i = 0; i < N * 2520; ++i) {
		if (state[i] != -1) continue;
		int pos = i % N, num = i / N;
		while (state[pos + num * N] == -1) {
			state[pos + num * N] = -2;
			num = (num + val[pos]) % 2520;
			pos = G[pos][num % deg[pos]];
		}
		int sz = 0;
		if (state[pos + num * N] == -2) {
			vector<int> vl;
			while (state[pos + num * N] == -2) {
				if (!flag[pos]) {
					flag[pos] = true;
					vl.push_back(pos);
					++sz;
				}
				state[pos + num * N] = -3;
				num = (num + val[pos]) % 2520;
				pos = G[pos][num % deg[pos]];
			}
			for (int j : vl) flag[j] = false;
		}
		else sz = state[pos + num * N];
		pos = i % N, num = i / N;
		while (state[pos + num * N] != sz) {
			state[pos + num * N] = sz;
			num = (num + val[pos]) % 2520;
			pos = G[pos][num % deg[pos]];
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y; --x;
		if (y >= 0) y %= 2520;
		else y = (2520 - (-y) % 2520) % 2520;
		cout << state[x + y * N] << '\n';
	}
	return 0;
}
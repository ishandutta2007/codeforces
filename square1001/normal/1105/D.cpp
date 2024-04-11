#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const vector<int> dx = { 0, 1, 0, -1 };
const vector<int> dy = { 1, 0, -1, 0 };
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int H, W, P;
	cin >> H >> W >> P;
	vector<int> V(P);
	for (int i = 0; i < P; ++i) cin >> V[i];
	vector<string> S(H);
	for (int i = 0; i < H; ++i) {
		cin >> S[i];
		for (int j = 0; j < W; ++j) {
			if ('1' <= S[i][j] && S[i][j] <= '9') --S[i][j];
		}
	}
	vector<vector<pair<int, int> > > nxt(P);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if ('0' <= S[i][j] && S[i][j] <= '9') {
				nxt[S[i][j] - '0'].push_back(make_pair(i, j));
			}
		}
	}
	int pass = 0, cur = 0;
	while (pass < P) {
		if (nxt[cur].empty()) {
			++pass;
		}
		else {
			pass = 0;
			queue<vector<int> > que;
			for (pair<int, int> i : nxt[cur]) {
				que.push({ i.first, i.second, V[cur] });
			}
			nxt[cur].clear();
			while (!que.empty()) {
				vector<int> u = que.front(); que.pop();
				if (u[2] == 0) {
					nxt[cur].push_back(make_pair(u[0], u[1]));
					continue;
				}
				for (int i = 0; i < 4; ++i) {
					int tx = u[0] + dx[i], ty = u[1] + dy[i];
					if (0 <= tx && tx < H && 0 <= ty && ty < W && S[tx][ty] == '.') {
						S[tx][ty] = char(cur + '0');
						que.push({ tx, ty, u[2] - 1 });
					}
				}
			}
		}
		cur = (cur + 1) % P;
	}
	vector<int> score(P);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if ('0' <= S[i][j] && S[i][j] <= '9') {
				++score[S[i][j] - '0'];
			}
		}
	}
	for (int i = 0; i < P; ++i) {
		if (i) cout << ' ';
		cout << score[i];
	}
	cout << endl;
	return 0;
}
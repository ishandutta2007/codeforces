#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N; string S[55]; bool vis[2][55][55]; vector<pair<int, int> > g[2];
void dfs(int x, int y, int id) {
	vis[id][x][y] = true;
	g[id].push_back(make_pair(x, y));
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i], ty = y + dy[i];
		if (0 <= tx && tx < N && 0 <= ty && ty < N && S[tx][ty] == '0' && !vis[id][tx][ty]) {
			dfs(tx, ty, id);
		}
	}
}
int sqr(int x) {
	return x * x;
}
int main() {
	cin >> N;
	int RS, CS, RG, CG;
	cin >> RS >> CS >> RG >> CG; --RS, --CS, --RG, --CG;
	for (int i = 0; i < N; ++i) cin >> S[i];
	dfs(RS, CS, 0);
	dfs(RG, CG, 1);
	int ans = 1 << 30;
	for (pair<int, int> i : g[0]) {
		for (pair<int, int> j : g[1]) {
			ans = min(ans, sqr(i.first - j.first) + sqr(i.second - j.second));
		}
	}
	cout << ans << endl;
	return 0;
}
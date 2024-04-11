#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 3100;
string s[maxN];
int d[maxN];
vector < int > x, y;

bool used[maxN][maxN];

pair < int, int > getPos(int u, int v) {
	int px = lower_bound(x.begin(), x.end(), u) - x.begin();
	int py = lower_bound(y.begin(), y.end(), v) - y.begin();
	return make_pair(px, py);
}

bool visited[maxN][maxN];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool valid(int u, int v) {
	return 0 <= u && u < x.size() && 0 <= v && v < y.size();
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && !visited[nx][ny] && !used[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int sx = 0, sy = 0;
	int n;
	cin >> n;
	x.push_back(0);
	y.push_back(0);
	x.push_back(-1);
	y.push_back(-1);
	x.push_back(1);
	y.push_back(1);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> d[i];
		if (s[i] == "R") {
			sx += d[i];
		}
		if (s[i] == "L") {
			sx -= d[i];
		}
		if (s[i] == "U") {
			sy += d[i];
		}
		if (s[i] == "D") {
			sy -= d[i];
		}
		for (int j = -1; j <= 1; ++j) {
			x.push_back(sx + j);
			y.push_back(sy + j);
		}
	}

	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	sort(y.begin(), y.end());
	y.resize(unique(y.begin(), y.end()) - y.begin());

	sx = 0, sy = 0;
	pair < int, int > current = getPos(sx, sy);
	used[current.first][current.second] = true;

	for (int i = 1; i <= n; ++i) {
		if (s[i] == "R") {
			sx += d[i];
		}
		if (s[i] == "L") {
			sx -= d[i];
		}
		if (s[i] == "U") {
			sy += d[i];
		}
		if (s[i] == "D") {
			sy -= d[i];
		}
		pair < int, int > buf = getPos(sx, sy);

		for (int j = min(current.first, buf.first); j <= max(current.first, buf.first); ++j) {
			for (int k = min(current.second, buf.second); k <= max(current.second, buf.second); ++k) {
				used[j][k] = true;
			}
		}
		current = buf;
	}

	for (int i = 0; i < x.size(); ++i) {
		for (int j = 0; j < y.size(); ++j) {
			if (i == 0 || i + 1 == x.size() || j == 0 || j + 1 == y.size()) {
				if (!used[i][j]) {
					dfs(i, j);
				}
			}
		}
	}

	long long res = 0;
	for (int i = 0; i < x.size(); ++i) {
		for (int j = 0; j < y.size(); ++j) {
			if (!visited[i][j]) {
				long long a = x[i] - x[i - 1];
				long long b = y[j] - y[j - 1];
				res += a * b;
			}
		}
	}

	cout << res << endl;

	return 0;
}
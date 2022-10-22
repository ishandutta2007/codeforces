#include<bits/stdc++.h>
const int maxn = 2001;
using std::cin;
using std::cout;
using std::endl;
const int go[][2] = {
	{ 1,  2}, { 1, -2}, {-1,  2}, {-1, -2},
	{ 2,  1}, { 2, -1}, {-2,  1}, {-2, -1},
};
int n, m;
typedef int AI[maxn];
typedef std::pair<int, int> pr;
inline void bfs(int x, int y, AI * a) {
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= m;++j) {
			a[i][j] = -1;
		}
	}
	std::queue<pr> q;
	const auto push = [&](int x, int y, int d) {
		if(a[x][y] == -1) {
			a[x][y] = d;
			q.emplace(x, y);
		}
	};
	for(push(x, y, 0);q.size();) {
		int x, y;
		std::tie(x, y) = q.front(); q.pop();
		for(int i = 0;i < 8;++i) {
			if(1 <= x + go[i][0] && x + go[i][0] <= n && 1 <= y + go[i][1] && y + go[i][1] <= m) {
				push(x + go[i][0], y + go[i][1], a[x][y] + 1);
			}
		}
	}
}
AI d1[maxn], d2[maxn];
struct reader {
	int a, b;
	inline void init(int a, int b) {
		this -> a = a;
		this -> b = b;
	}
	inline void flush() { cin >> a >> b; }
	inline int test(int x, int y) {
		for(int i = 0;i < 8;++i) {
			if(x + go[i][0] == a && y + go[i][1] == b) return 1;
		}
		return 0;
	}
} opp;
inline void Go(int nx, int ny, int tx, int ty, AI * d, int yes = 0) {
	if(nx == tx && ny == ty) return ;
	if(nx == opp.a && ny == opp.b) exit(0);
	if(yes) opp.flush();
	for(int i = 0;i < 8;++i) {
		if(1 <= nx + go[i][0] && nx + go[i][0] <= n && 1 <= ny + go[i][1] && ny + go[i][1] <= m) {
			if(d[nx + go[i][0]][ny + go[i][1]] < d[nx][ny] && !opp.test(nx + go[i][0], ny + go[i][1])) {
				cout << nx + go[i][0] << ' ' << ny + go[i][1] << endl;
				return Go(nx + go[i][0], ny + go[i][1], tx, ty, d, 1);
			}
		}
	}
	exit(1);
}
int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bfs(n / 2, m / 2, d1);
	bfs(n / 2 + 1, m / 2, d2);
	if((x1 + y1) % 2 == (x2 + y2) % 2) {
		if(d2[x2][y2] < d1[x1][y1]) {
			cout << "BLACK" << endl;
			opp.flush();
			Go(x2, y2, n / 2 + 1, m / 2, d2);
			return 0;
		}
		if(d1[x2][y2] - 1 < d1[x1][y1]) {
			cout << "BLACK" << endl;
			opp.flush();
			Go(x2, y2, n / 2, m / 2, d1);
			Go(n / 2, m / 2, n / 2 + 1, m / 2, d2, x2 != n / 2 || y2 != m / 2);
			return 0;
		}
		cout << "WHITE" << endl;
		opp.init(x2, y2);
		Go(x1, y1, n / 2, m / 2, d1);
	} else {
		if(d1[x1][y1] <= d2[x2][y2]) {
			cout << "WHITE" << endl;
			opp.init(x2, y2);
			Go(x1, y1, n / 2, m / 2, d1);
			return 0;
		}
		if(d2[x1][y1] - 1 <= d2[x2][y2]) {
			cout << "WHITE" << endl;
			opp.init(x2, y2);
			Go(x1, y1, n / 2 + 1, m / 2, d2);
			Go(n / 2 + 1, m / 2, n / 2, m / 2, d1, x1 != n / 2 + 1 || y1 != m / 2);
			return 0;
		}
		cout << "BLACK" << endl;
		opp.flush();
		Go(x2, y2, n / 2 + 1, m / 2, d2);
	}
}
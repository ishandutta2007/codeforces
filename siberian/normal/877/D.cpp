#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1010, INF = 1e9;
int n, m, k;
char table[MAXN][MAXN];

int d[MAXN][MAXN];

struct pt{
	int x, y;
	pt() {}
	pt(int _x, int _y) {
		x = _x, y = _y;
	}
};

set<int> ban[2][MAXN];
set<int> have[2][MAXN];

queue<pt> q;

void relax(pt v) {
	int x = v.x;
	int y = v.y;
	int dist = d[x][y];
	have[0][x].erase(y);
	have[1][y].erase(x);

	while (true) {
		auto it = have[1][y].lower_bound(x);
		if (it == have[1][y].end()) break;
		int nx = *it;
		if (nx - v.x > k) break;
		auto it2 = ban[1][y].lower_bound(x);
		if (it2 != ban[1][y].end() && *it2 <= nx) break;
		
		have[1][y].erase(nx);
		have[0][nx].erase(y);
		d[nx][y] = dist + 1;
		x = nx;

		q.push({x, y});
	}
	//return;
	x = v.x;
	y = v.y;
	while (true) {
		auto it = have[1][y].lower_bound(x);
		if (it == have[1][y].begin()) break;
		--it;
		int nx = *it;
		if (v.x - nx > k) break;
		auto it2 = ban[1][y].lower_bound(x);
		if (it2 != ban[1][y].begin() && *(--it2) >= nx) break;
		
		have[1][y].erase(nx);
		have[0][nx].erase(y);
		d[nx][y] = dist + 1;
		x = nx;

		q.push({x, y});
	}

	x = v.x;
	y = v.y;

	while (true) {
		auto it = have[0][x].lower_bound(y);
		if (it == have[0][x].end()) break;
		int ny = *it;
		if (ny - v.y > k) break;
		auto it2 = ban[0][x].lower_bound(y);
		if (it2 != ban[0][x].end() && *it2 <= ny) break;
		
		have[0][x].erase(ny);
		have[1][ny].erase(x);
		d[x][ny] = dist + 1;
		y = ny;
		q.push({x, y});
	}
	x = v.x;
	y = v.y;

	while (true) {
		auto it = have[0][x].lower_bound(y);
		if (it == have[0][x].begin()) break;
		--it;
		int ny = *it;
		if (v.y - ny > k) break;
		auto it2 = ban[0][x].lower_bound(y);
		if (it2 != ban[0][x].begin() && *(--it2) >= ny) break;
		
		have[0][x].erase(ny);
		have[1][ny].erase(x);
		d[x][ny] = dist + 1;
		y = ny;
		q.push({x, y});
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
			d[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			have[0][i].insert(j);
			have[1][j].insert(i);
			if (table[i][j] == '#') {
				ban[0][i].insert(j);
				ban[1][j].insert(i);
			}
		}
	}
	pt s, f;
	cin >> s.x >> s.y >> f.x >> f.y;
	s.x--;
	s.y--;
	f.x--;
	f.y--;
	d[s.x][s.y] = 0;
	q.push(s);
	while (!q.empty()) {
		pt v = q.front();
		q.pop();
		relax(v);
		/*cout << "d = " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		//return;

	}


	if (d[f.x][f.y] == INF) d[f.x][f.y] = -1;
	cout << d[f.x][f.y] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
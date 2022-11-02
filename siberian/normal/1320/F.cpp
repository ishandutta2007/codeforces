#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define left left228
#define right right228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define FAST_ALLOCATOR_MEMORY 150*1024*1024
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int) FAST_ALLOCATOR_MEMORY];
 
inline void *operator new(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int) FAST_ALLOCATOR_MEMORY);
    return (void *) res;
}
 
inline void operator delete(void *) noexcept {}
 
inline void operator delete(void *, size_t) {}
#endif

struct triple{
	int x, y, z;
	triple() {}
	triple(int _x, int _y, int _z) {
		x = _x, y = _y, z = _z;
	}
};

int n, m, k;

vector<vector<int>> up, down, left, right, top, bottom;

void Read(vector<vector<int>> & have, int a, int b) {
	have.resize(a, vector<int> (b));
	for (auto &i : have)
		for (auto &j : i)
			cin >> j;
}

void read() {
	cin >> n >> m >> k;
	Read(left, m, k);
	Read(right, m, k);
	Read(top, n, k);
	Read(bottom, n, k);
	Read(down, n, m);
	Read(up, n, m);
}

bool operator==(const triple & a, const triple & b) {
	return tie(a.x, a.y, a.z) == tie(b.x, b.y, b.z);
}

vector<vector<vector<triple>>> par[3];
vector<vector<vector<int>>> Min[3], Max[3];

triple get_par(triple a, int it) {
	if (a == par[it][a.x][a.y][a.z]) return a;
	return par[it][a.x][a.y][a.z] = get_par(par[it][a.x][a.y][a.z], it);
}

void uni(triple a, triple b, int it) {
	a = get_par(a, it);
	b = get_par(b, it);
	if (a == b) return;
	par[it][b.x][b.y][b.z] = a;
	chkmin(Min[it][a.x][a.y][a.z], Min[it][b.x][b.y][b.z]);
	chkmax(Max[it][a.x][a.y][a.z], Max[it][b.x][b.y][b.z]);
}

void no() {
	cout << -1 << endl;
	exit(0);
}

vector<vector<vector<bool>>> used;
queue<triple> q;

int get_color(int x, int y, int z) {
	set<int> color;
	triple a;
	
	// get_left
	if (x != 0) {
		a = {x - 1, y, z};
		a = get_par(a, 0);
	}
	if (x == 0 || (Min[0][a.x][a.y][a.z] == 0 && used[x - 1][y][z])) {
		color.insert(left[y][z]);
	}

	// get_right
	if (x != n - 1) {
		a = {x + 1, y, z};
		a = get_par(a, 0);
	}
	if (x == n - 1 || (Max[0][a.x][a.y][a.z] == n - 1 && used[x + 1][y][z])) {
		color.insert(right[y][z]);
	} 

	// get top
	if (y != 0) {
		a = {x, y - 1, z};
		a = get_par(a, 1);
	}
	if (y == 0 || (Min[1][a.x][a.y][a.z] == 0 && used[x][y - 1][z])) {
		color.insert(top[x][z]);
	}

	// get bottom
	if (y != m - 1) {
		a = {x, y + 1, z};
		a = get_par(a, 1);
	}
	if (y == m - 1 || (Max[1][a.x][a.y][a.z] == m - 1 && used[x][y + 1][z])) {
		color.insert(bottom[x][z]);
	}

	// get down
	if (z != 0) {
		a = {x, y, z - 1};
		a = get_par(a, 2);
	}
	if (z == 0 || (Min[2][a.x][a.y][a.z] == 0 && used[x][y][z - 1])) {
		color.insert(down[x][y]);
	}
	
	// get up
	if (z != k - 1) {
		a = {x, y, z + 1};
		a = get_par(a, 2);
	}	
	if (z == k - 1 || (Max[2][a.x][a.y][a.z] == k - 1 && used[x][y][z + 1])) {
		color.insert(up[x][y]);
	}

	if (color.empty()) return -1;
	if (color.size() >= 2) return 0;
	return *color.begin();
}

void build() {
	used.assign(n, vector<vector<bool>> (m, vector<bool> (k, false)));
	for (int i = 0; i < 3; i++) {
		par[i].resize(n, vector<vector<triple>> (m, vector<triple> (k)));
		Min[i].resize(n, vector<vector<int>> (m, vector<int> (k)));
		Max[i].resize(n, vector<vector<int>> (m, vector<int> (k)));
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int z = 0; z < k; z++) {
				for (int it = 0; it < 3; it++) {
					par[it][x][y][z] = {x, y, z};
				}
				Min[0][x][y][z] = x;
				Max[0][x][y][z] = x;
				Min[1][x][y][z] = y;
				Max[1][x][y][z] = y;
				Min[2][x][y][z] = z;
				Max[2][x][y][z] = z;
			}
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int z = 0; z < k; z++) {
				if (!get_color(x, y, z)) {
					q.push({x, y, z});
					used[x][y][z] = true;
				}
			}
		}
	}
}

vector<int> dx = {-1, 1, 0, 0, 0, 0}; 
vector<int> dy = {0, 0, -1, 1, 0, 0}; 
vector<int> dz = {0, 0, 0, 0, -1, 1};

bool check(int x, int y, int z) {
	return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k;
}

void del(int x, int y, int z) {
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];	
		if (!check(nx, ny, nz)) continue;
		if (!used[nx][ny][nz]) continue;
		uni({x, y, z}, {nx, ny, nz}, i / 2);
	}
}

void bfs() {
	while (!q.empty()) {
		auto v = q.front();
		int x = v.x, y = v.y, z = v.z;
		q.pop();
		del(x, y, z);
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (!check(nx, ny, nz)) continue;
			if (get_color(nx, ny, nz)) continue;
			
			if (used[nx][ny][nz]) {
				auto a = triple(nx, ny, nz);
				a = get_par(a, i / 2);
				if (i / 2 == 0) {
					if (i % 2 == 0) {
						nx = Min[i / 2][a.x][a.y][a.z] - 1;
					}
					else {
						nx = Max[i / 2][a.x][a.y][a.z] + 1;
					}
				}
				else if (i / 2 == 1) {
					if (i % 2 == 0) {
						ny = Min[i / 2][a.x][a.y][a.z] - 1;
					}
					else {
						ny = Max[i / 2][a.x][a.y][a.z] + 1;
					}
				}
				else {
					if (i % 2 == 0) {
						nz = Min[i / 2][a.x][a.y][a.z] - 1;
					}
					else {
						nz = Max[i / 2][a.x][a.y][a.z] + 1;
					}
				}
				if (!check(nx, ny, nz)) continue;
				if (get_color(nx, ny, nz)) continue;
			}
			if (used[nx][ny][nz]) continue;
			used[nx][ny][nz] = true;
			q.push({nx, ny, nz});
		}
	}
}

void check_ans() {
	for (int y = 0; y < m; y++) {
		for (int z = 0; z < k; z++) {
			bool flag = false;
			for (int x = 0; x < n; x++) {
				if (!used[x][y][z]) {
					flag = true;
				}
			}
			if (!flag) {
				if (left[y][z] || right[y][z]) {
					no();
				}
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int z = 0; z < k; z++) {
			bool flag = false;
			for (int y = 0; y < m; y++) {
				if (!used[x][y][z]) {
					flag = true;
				}
			}
			if (!flag) {
				if (top[x][z] || bottom[x][z]) {
					no();
				}
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			bool flag = false;
			for (int z = 0; z < k; z++) {
				if (!used[x][y][z]) {
					flag = true;
				}
			}
			if (!flag) {
				if (up[x][y] || down[x][y]) {
					no();
				}
			}
		}
	}
}

void run() {
	build();
	bfs();
	check_ans();
}

void write() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int z = 0; z < k; z++) {
				int ans = get_color(x, y, z);
				if (ans == -1) ans = 0;
				if (used[x][y][z]) ans = 0;
				cout << ans << " ";
			}
		}
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}
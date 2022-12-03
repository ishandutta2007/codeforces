#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<ll, int> ll_i;
struct edge { int v, w, h; };
const int INF = INT_MAX / 10;
const int MOD = 1e9 + 7;

struct dice {
	mt19937 mt;
	dice() {
		random_device rd;
		mt = mt19937(rd());
	}
	int operator()(int x) { return this->operator()(0, x - 1); }
	int operator()(int x, int y) {
		uniform_int_distribution<int> dist(x, y);
		return dist(mt);
	}
} dc;

bool check(vector<vector<int>> a) {
	int H = a.size(), W = a[0].size();
	rep(y, H) rep(x, W - 1) {
		int z = a[y][x], _z = a[y][x + 1];
		if (abs(z / W - _z / W) + abs(z % W - _z % W) == 1)
			return false;
	}
	rep(y, H - 1) rep(x, W) {
		int z = a[y][x], _z = a[y + 1][x];
		if (abs(z / W - _z / W) + abs(z % W - _z % W) == 1)
			return false;
	}
	return true;
}

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void solve(int H, int W) {
	vector<int> p(H * W);
	rep(z, H * W) p[z] = z;
	shuffle(p.begin(), p.end(), dc.mt);
	vector<vector<int>> a(H, vector<int>(W));
	rep(z, H * W) a[z / W][z % W] = p[z];
	queue<int> q;
	rep(z, H * W) q.push(z);
	while (q.size()) {
		// cout << q.size() << endl;
		int z = q.front(); q.pop();
		int y = z / W, x = z % W;
		bool ok = true;
		rep(k, 4) {
			int _y = y + dy[k], _x = x + dx[k];
			if (0<=_y && _y<H && 0<=_x && _x<W) {
				int t = a[y][x], _t = a[_y][_x];
				if (abs(t / W - _t / W) + abs(t % W - _t % W) == 1)
					ok = false;
			}
		}
		if (ok) continue;
		int _y = dc(H), _x = dc(W);
		swap(a[y][x], a[_y][_x]);
		q.push(y * W + x), q.push(_y * W + _x);
	}
	rep(y, H) {
		rep(x, W) printf("%d ", a[y][x] + 1);
		printf("\n");
	}
	if (!check(a)) {
		cout << "ERR" << endl;
		exit(0);
	}
}

int main() {
	int H, W; cin >> H >> W;
	bool ok = true;
	if (H * W == 2) ok = false;
	if (H * W == 3) ok = false;
	if (H == 2 && W == 2) ok = false;
	if (H == 2 && W == 3) ok = false;
	if (H == 3 && W == 2) ok = false;
	if (!ok) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	solve(H, W);
	/*
	vector<int> p(9);
	rep(x, 9) p[x] = x;
	do {
		vector<vector<int>> a(3, vector<int>(3));
		rep(z, 9) a[z / 3][z % 3] = p[z];
		if (check(a)) {
			rep(y, 3) {
				rep(x, 3) cout << a[y][x] << ' ';
				cout << endl;
			}
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	*/
	/*
	for (int H = 3; H <= 100; H++)
		for (int W = 90000; W <= 100000; W++) {
			if (H * W == 2) continue;
			if (H * W == 3) continue;
			if (H == 2 && W == 2) continue;
			if (H == 2 && W == 3) continue;
			if (H == 3 && W == 2) continue;
			cout << H << ' ' << W << endl;
			for (;;) {
				vector<int> p(H * W);
				rep(z, H * W) p[z] = z;
				shuffle(p.begin(), p.end(), dc.mt);
				vector<vector<int>> a(H, vector<int>(W));
				rep(z, H * W) a[z / W][z % W] = p[z];
				if (check(a)) break;
			}
		}
	*/
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool check(int H, int W, vector<string> a) {
	rep(y0, H) rep(x0, W) rep(k, 8) {
		bool ok = true;
		rep(t, 5) {
			int y = y0 + dy[k] * t;
			int x = x0 + dx[k] * t;
			if (0<=y && y<H && 0<=x && x<W && a[y][x]=='X');
			else ok = false;
		}
		if (ok) return true;
	}
	return false;
}

int main() {
	int H = 10, W = 10;
	vector<string> a(H);
	rep(y, H) cin >> a[y];
	rep(y, H) rep(x, W) if (a[y][x] == '.') {
		a[y][x] = 'X';
		if (check(H, W, a)) {
			cout << "YES" << endl;
			return 0;
		}
		a[y][x] = '.';
	}
	cout << "NO" << endl;
}
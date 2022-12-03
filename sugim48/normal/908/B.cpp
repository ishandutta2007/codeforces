#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int main() {
	int H, W; cin >> H >> W;
	vector<string> a(H);
	rep(y, H) cin >> a[y];
	int ys, xs, yt, xt;
	rep(y, H) rep(x, W) {
		if (a[y][x] == 'S') a[y][x] = '.', ys = y, xs = x;
		if (a[y][x] == 'E') a[y][x] = '.', yt = y, xt = x;
	}
	string s; cin >> s;
	vector<int> p(4);
	rep(k, 4) p[k] = k;
	int ans = 0;
	do {
		int y = ys, x = xs;
		bool ok = false;
		for (char c: s) {
			int k = p[c - '0'];
			y += dy[k], x += dx[k];
			if (!(0<=y && y<H && 0<=x && x<W && a[y][x]=='.')) break;
			if (y == yt && x == xt) ok = true;
		}
		if (ok) ans++;
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << endl;
}
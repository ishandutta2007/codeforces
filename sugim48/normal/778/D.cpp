#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
const int _MOD = 1000000009;
double EPS = 1e-10;
ll INF = INT_MAX / 2;

vector<i_i> his;

void dfs(int H, int W, vector<string>& a, int y, int x, bool z) {
	if (z) {
		if (a[y][x] != 'U') return;
		dfs(H, W, a, y, x + 1, !z);
		a[y][x] = 'L'; a[y][x + 1] = 'R';
		a[y + 1][x] = 'L'; a[y + 1][x + 1] = 'R';
		his.pb(i_i(y, x));
	}
	else {
		if (a[y][x] != 'L') return;
		dfs(H, W, a, y + 1, x, !z);
		a[y][x] = 'U'; a[y][x + 1] = 'U';
		a[y + 1][x] = 'D'; a[y + 1][x + 1] = 'D';
		his.pb(i_i(y, x));
	}
}

void solve(int H, int W, vector<string> a) {
	for (int y = 0; y + 1 < H; y++)
		for (int x = 0; x + 1 < W; x++)
			dfs(H, W, a, y, x, W % 2 == 0);
}

int main() {
	int H, W; cin >> H >> W;
	vector<string> a(H), b(H);
	rep(y, H) cin >> a[y];
	rep(y, H) cin >> b[y];
	solve(H, W, a);
	vector<i_i> ans = his;
	his.clear();
	solve(H, W, b);
	while (his.size()) {
		ans.pb(his.back());
		his.pop_back();
	}
	cout << ans.size() << endl;
	for (i_i yx: ans) printf("%d %d\n", yx.first + 1, yx.second + 1);
}
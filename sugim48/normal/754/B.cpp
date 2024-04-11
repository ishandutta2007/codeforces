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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool check(vector<string> a) {
	rep(y0, 4) rep(x0, 4) rep(k, 8) {
		int y = y0, x = x0;
		bool ok = true;
		rep(t, 3) {
			if (0<=y && y<4 && 0<=x && x<4 && a[y][x] == 'x');
			else ok = false;
			y += dy[k], x += dx[k];
		}
		if (ok) return true;
	}
	return false;
}

int main() {
	vector<string> a(4);
	rep(y, 4) cin >> a[y];
	rep(y, 4) rep(x, 4) if (a[y][x] == '.') {
		a[y][x] = 'x';
		if (check(a)) {
			cout << "YES" << endl;
			return 0;
		}
		a[y][x] = '.';
	}
	cout << "NO" << endl;
}
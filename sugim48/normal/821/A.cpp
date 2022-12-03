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
struct edge { int u, v; ll w; };

const int MOD = 1e9 + 7;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<vector<int> > a(N, vector<int>(N));
	rep(y, N) rep(x, N) cin >> a[y][x];
	bool ok = true;
	rep(y, N) rep(x, N) if (a[y][x] != 1) {
		bool wei = false;
		rep(_y, N) rep(_x, N) if (a[_y][x] + a[y][_x] == a[y][x]) wei = true;
		if (!wei) ok = false;
	}
	cout << (ok ? "Yes" : "No") << endl;
}
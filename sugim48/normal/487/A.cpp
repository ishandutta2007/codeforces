#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;

int calc(int ay, int dy, int hm, int am, int dm) {
	int x = ay - dm;
	if (x <= 0) return 0;
	int t = (hm + x - 1) / x;
	int y = max(0, am - dy);
	return t * y + 1;
}

int main() {
	int hy, ay, dy; cin >> hy >> ay >> dy;
	int hm, am, dm; cin >> hm >> am >> dm;
	int h, a, d; cin >> h >> a >> d;
	int mini = INT_MAX;
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 100; j++) {
			int x = calc(ay + i, dy + j, hm, am, dm);
			if (x == 0) continue;
			int k = max(0, x - hy);
			mini = min(mini, k * h + i * a + j * d);
		}
	cout << mini << endl;
}
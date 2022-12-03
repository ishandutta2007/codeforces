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
double EPS = 1e-10;

string unko(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

string _unko(int x) {
	stringstream ss;
	if (x >= 0) ss << "+(";
	else ss << "-(";
	ss << abs(x);
	return ss.str();
}

int main() {
	int n; cin >> n;
	vector<int> x(n), y(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> r[i];
		x[i] = x[i] / 2 * 2;
		y[i] = y[i] / 2 * 2;
	}
	string f = unko(x[0]), g = unko(y[0]);
	int _dx = 0, _dy = 0;
	for (int i = 0; i + 1 < n; i++) {
		int dx = (x[i + 1] - x[i]) / 2, dy = (y[i + 1] - y[i]) / 2;
		string s = "*(abs((t-" + unko(i) + "))+(t-" + unko(i) + "))";
		f = "(" + f + _unko(dx - _dx) + s + "))";
		g = "(" + g + _unko(dy - _dy) + s + "))";
		_dx = dx; _dy = dy;
	}
	cout << f << endl;
	cout << g << endl;
}
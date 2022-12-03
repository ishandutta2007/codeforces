#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
struct edge { int u, v; ll w; };

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	if (x1 == x2) {
		x3 = x1 + y2 - y1; y3 = y1;
		x4 = x1 + y2 - y1; y4 = y2;
	}
	else if (y1 == y2) {
		x3 = x1; y3 = y1 + x2 - x1;
		x4 = x2; y4 = y1 + x2 - x1;
	}
	else if (abs(x2 - x1) == abs(y2 - y1)) {
		x3 = x1; y3 = y2;
		x4 = x2; y4 = y1;
	}
	else {
		cout << -1 << endl;
		return 0;
	}
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
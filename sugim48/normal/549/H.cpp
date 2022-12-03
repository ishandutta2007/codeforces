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
double EPS = 1e-10;

d_d f(int x, int y, double z) {
	double mini = min(min((x + z) * (y + z), (x + z) * (y - z)), min((x - z) * (y + z), (x - z) * (y - z)));
	double maxi = max(max((x + z) * (y + z), (x + z) * (y - z)), max((x - z) * (y + z), (x - z) * (y - z)));
	return d_d(mini, maxi);
}

int main() {
	int a, b; cin >> a >> b;
	int c, d; cin >> c >> d;
	double lb = 0, ub = 1e10;
	for (int t = 0; t < 100; t++) {
		double mid = (lb + ub) / 2;
		d_d ad = f(a, d, mid), bc = f(b, c, mid);
		if (ad.first - bc.second <= 0 && 0 <= ad.second - bc.first)
			ub = mid;
		else
			lb = mid;
	}
	printf("%.15f\n", lb);
}
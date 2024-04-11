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
#include <list>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 10007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int a, b; cin >> a >> b;
	double mi = DBL_MAX;
	int N; cin >> N;
	while (N--) {
		int x, y, v; cin >> x >> y >> v;
		mi = min(mi, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
	}
	printf("%.15f\n", mi);
}
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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<int, char> i_c;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> x(100001), y(100001);
	vector<int> b(100001, INT_MAX);
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		for (int r = 0; r < 18; r++)
			for (int l = 0; l < 18; l++) {
				ll _a = (a >> r) << l;
				if (_a <= 100000)
					b[_a] = min(b[_a], l + r);
			}
		for (int r = 0; r < 18; r++)
			for (int l = 0; l < 18; l++) {
				ll _a = (a >> r) << l;
				if (_a <= 100000 && b[_a] < INT_MAX) {
					x[_a]++;
					y[_a] += b[_a];
					b[_a] = INT_MAX;
				}
			}
	}
	int mini = INT_MAX;
	for (int j = 1; j <= 100000; j++)
		if (x[j] == n)
			mini = min(mini, y[j]);
	cout << mini << endl;
}
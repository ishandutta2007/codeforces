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

int main() {
	vector< vector<int> > a(3);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		a[t - 1].push_back(i);
	}
	int w = min(a[0].size(), min(a[1].size(), a[2].size()));
	cout << w << endl;
	for (int j = 0; j < w; j++)
		cout << a[0][j] << ' ' << a[1][j] << ' ' << a[2][j] << endl;
}
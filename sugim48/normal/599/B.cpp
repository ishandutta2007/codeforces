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
	int n, m; cin >> n >> m;
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++) {
		int f; cin >> f; f--;
		v[f].push_back(i);
	}
	bool imp = false, amb = false;
	vector<int> a(m);
	for (int j = 0; j < m; j++) {
		int b; cin >> b; b--;
		int k = v[b].size();
		if (k == 0) imp = true;
		if (k == 1) a[j] = v[b][0];
		if (k >= 2) amb = true;
	}
	if (imp) cout << "Impossible" << endl;
	else if (amb) cout << "Ambiguity" << endl;
	else {
		cout << "Possible" << endl;
		for (int j = 0; j < m; j++)
			cout << a[j] + 1 << ' ';
		cout << endl;
	}
}
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, k, a; cin >> n >> k >> a;
	int m; cin >> m;
	vector<int> x(m);
	for (int j = 0; j < m; j++)
		scanf("%d", &x[j]);
	int lb = 0, ub = m + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		vector<int> y;
		y.push_back(0);
		y.push_back(n + 1);
		for (int j = 0; j < mid; j++)
			y.push_back(x[j]);
		sort(y.begin(), y.end());
		int sum = 0;
		for (int k = 0; k + 1 < y.size(); k++) {
			int dy = y[k + 1] - y[k];
			sum += dy / (a + 1);
		}
		if (sum >= k) lb = mid;
		else ub = mid;
	}
	cout << (lb < m ? lb + 1 : -1) << endl;
}
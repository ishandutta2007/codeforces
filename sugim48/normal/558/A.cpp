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

int f(vector<i_i>& v, vector<i_i>& w) {
	int sum = 0;
	for (int i = 0; ; i++) {
		vector<i_i>& x = (i % 2 == 0 ? v : w);
		if (i / 2 < x.size()) sum += x[i / 2].second;
		else break;
	}
	return sum;
}

int main() {
	int n; cin >> n;
	vector<i_i> v, w;
	while (n--) {
		int x, a; cin >> x >> a;
		if (x > 0) v.push_back(i_i(x, a));
		if (x < 0) w.push_back(i_i(-x, a));
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	cout << max(f(v, w), f(w, v)) << endl;
}
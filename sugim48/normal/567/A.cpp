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

int main() {
	int n; cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++) {
		int mini = INT_MAX;
		if (i - 1 >= 0) mini = min(mini, x[i] - x[i - 1]);
		if (i + 1 < n) mini = min(mini, x[i + 1] - x[i]);
		int maxi = max(x[i] - x[0], x[n - 1] - x[i]);
		cout << mini << ' ' << maxi << endl;
	}
}
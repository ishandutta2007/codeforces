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
	int n, x1, x2; cin >> n >> x1 >> x2;
	vector<ll_ll> a(n);
	for (int i = 0; i < n; i++) {
		int k, b; cin >> k >> b;
		a[i] = ll_ll((ll)k * x1 + b, (ll)k * x2 + b);
	}
	sort(a.begin(), a.end());
	bool yes = false;
	for (int i = 0; i + 1 < n; i++)
		if (a[i].first < a[i + 1].first && a[i].second > a[i + 1].second)
			yes = true;
	cout << (yes ? "YES" : "NO") << endl;
}
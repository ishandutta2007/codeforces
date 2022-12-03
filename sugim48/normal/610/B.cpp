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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mi = INT_MAX;
	for (int i = 0; i < n; i++)
		mi = min(mi, a[i]);
	vector<int> v;
	for (int i = 0; i < n; i++)
		if (a[i] == mi)
			v.push_back(i);
	v.push_back(v[0] + n);
	int ma = 0;
	for (int k = 0; k + 1 < v.size(); k++)
		ma = max(ma, v[k + 1] - v[k]);
	cout << (ll)n * mi + ma - 1 << endl;
}
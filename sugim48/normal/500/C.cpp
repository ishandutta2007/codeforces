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
	vector<int> w(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int j = 0; j < m; j++) {
		cin >> b[j];
		b[j]--;
	}
	vector<bool> a(n);
	vector<int> v;
	for (int j = 0; j < m; j++) {
		int& i = b[j];
		if (a[i]) continue;
		a[i] = true;
		v.push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (!a[i])
			v.push_back(i);
	ll ans = 0;
	for (int j = 0; j < m; j++) {
		int i;
		for (i = 0; v[i] != b[j]; i++)
			ans += w[v[i]];
		v.erase(v.begin() + i);
		v.insert(v.begin(), b[j]);
	}
	cout << ans << endl;
}
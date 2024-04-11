#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	vector<int> a(n);
	int m = n / 2 + 1;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (a[i] >= y) m--;
	}
	m = max(0, m);
	if (k + m > n) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = k; i < k + m; i++)
		a[i] = y;
	for (int i = k + m; i < n; i++)
		a[i] = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	if (sum > x) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = k; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
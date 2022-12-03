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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<i_i> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i_i(a[i] % 10, i);
	sort(p.begin(), p.end());
	for (int j = n - 1; j >= 0; j--) {
		int i = p[j].second, x = 10 - a[i] % 10;
		if (a[i] % 10 && k >= x) {
			k -= x;
			a[i] += x;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] / 10;
	sum = min(n * 10, sum + k / 10);
	cout << sum << endl;
}
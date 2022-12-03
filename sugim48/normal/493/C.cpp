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
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m; cin >> m;
	vector<int> b(m);
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	vector<int> c(n + m);
	for (int i = 0; i < n; i++)
		c[i] = a[i];
	for (int j = 0; j < m; j++)
		c[n + j] = b[j];
	c.push_back(0);
	c.push_back(INT_MAX);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	i_i maxi(INT_MIN, 0);
	for (int k = 0; k < c.size(); k++) {
		int i = upper_bound(a.begin(), a.end(), c[k]) - a.begin();
		int j = upper_bound(b.begin(), b.end(), c[k]) - b.begin();
		int pa = i * 2 + (n - i) * 3, pb = j * 2 + (m - j) * 3;
		maxi = max(maxi, i_i(pa - pb, pa));
	}
	int pa = maxi.second, pb = pa - maxi.first;
	cout << pa << ':' << pb << endl;
}
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
int INF = INT_MAX / 10;

int main() {
	int n; cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	n = x.size();
	int a, b; cin >> a >> b;
	vector<int> v(a - b + 1, INT_MAX);
	for (int i = 0; i < n; i++) {
		for (int j = b / x[i] * x[i] - 1; j <= a; j += x[i])
			if (j - x[i] + 1 >= b)
				v[j - b] = j - x[i] + 1;
		if (a / x[i] * x[i] >= b)
			v[a - b] = min(v[a - b], a / x[i] * x[i]);
	}
	for (int j = a - 1; j > b; j--)
		v[j - b] = min(v[j - b], v[j + 1 - b]);
	int cnt = 0;
	for (int j = a; j > b; j = min(j - 1, v[j - b]))
		cnt++;
	cout << cnt << endl;
}
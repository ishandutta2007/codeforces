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
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		a[p - 1] = i;
	}
	vector<int> b;
	b.push_back(0);
	for (int i = 1; i <= n - 1; i++)
		if (a[i - 1] > a[i])
			b.push_back(i);
	b.push_back(n);
	int ma = 0;
	for (int k = 0; k + 1 < b.size(); k++)
		ma = max(ma, b[k + 1] - b[k]);
	cout << n - ma << endl;
}
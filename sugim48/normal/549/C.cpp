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

int f(int e, int o, int t) {
	if (t == 0) return o % 2;
	if (e > t && o > t) return -1;
	if (o <= t) return 0;
	if (e <= t) return (e + o - t * 2) % 2;
}

int main() {
	int n, k; cin >> n >> k;
	int e = 0, o = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a % 2 == 0) e++;
		else o++;
	}
	bool stannis = false;
	if ((n - k) % 2 == 0) {
		if (f(e, o, (n - k) / 2) == 1)
			stannis = true;
	}
	else {
		if (e && f(e - 1, o, (n - k) / 2) != 0)
			stannis = true;
		if (o && f(e, o - 1, (n - k) / 2) != 0)
			stannis = true;
	}
	cout << (stannis ? "Stannis" : "Daenerys") << endl;
}
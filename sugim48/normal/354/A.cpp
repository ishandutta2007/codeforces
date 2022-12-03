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
	int n, l, r, Ql, Qr;
	cin >> n >> l >> r >> Ql >> Qr;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++)
		a[i + 1] = a[i] + w[i];
	for (int i = n - 1; i >= 0; i--)
		b[i] = b[i + 1] + w[i];
	int mi = INT_MAX;
	for (int i = 0; i <= n; i++) {
		int x = i, y = n - i;
		mi = min(mi, a[i] * l + Ql * max(0, x - y - 1) + b[i] * r + Qr * max(0, y - x - 1));
	}
	cout << mi << endl;
}
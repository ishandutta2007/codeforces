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
int INF = INT_MAX / 4;

int c = 316;

int main() {
	int n, m; cin >> n >> m;
	vector<ll> l(n), h(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &l[i]);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &h[i]);
		h[i] *= 2;
	}
	vector<ll> L(n / c), X(n / c), Y(n / c), Z(n / c);
	for (int k = 0; k < n / c; k++) {
		X[k] = LLONG_MIN;
		for (int i = k * c; i < (k + 1) * c; i++) {
			Z[k] = max(Z[k], h[i] + L[k] + X[k]);
			X[k] = max(X[k], h[i] - L[k]);
			Y[k] = max(Y[k], h[i] + L[k]);
			L[k] += l[i];
		}
	}
	while (m--) {
		int a, b; cin >> a >> b;
		a--;
		if (a <= b) a += n;
		ll d = 0, x = LLONG_MIN, z = 0;
		for (int i = b; i < a;) {
			int j = i % n;
			if (j % c == 0 && j + c <= n && i + c <= a) {
				z = max(z, Z[j / c]);
				z = max(z, Y[j / c] + d + x);
				x = max(x, X[j / c] - d);
				d += L[j / c];
				i += c;
			}
			else {
				z = max(z, h[j] + d + x);
				x = max(x, h[j] - d);
				d += l[j];
				i++;
			}
		}
		printf("%I64d\n", z);
	}
}
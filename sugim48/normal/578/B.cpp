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
	int n, k, x; cin >> n >> k >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	vector<ll> l(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++)
		l[i] = l[i - 1] | a[i - 1];
	for (int i = n - 1; i >= 0; i--)
		r[i] = r[i + 1] | a[i];
	ll maxi = 0;
	for (int i = 0; i < n; i++) {
		ll z = a[i];
		for (int t = 0; t < k; t++)
			z *= x;
		maxi = max(maxi, l[i] | z | r[i + 1]);
	}
	cout << maxi << endl;
}
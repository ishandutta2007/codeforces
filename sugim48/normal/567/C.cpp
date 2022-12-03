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
#include <unordered_map>
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
	int n; ll k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	unordered_map<ll, ll> x, y;
	ll sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += y[a[i] * k];
		y[a[i]] += x[a[i] * k];
		x[a[i]]++;
	}
	cout << sum << endl;
}
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
#include <list>
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
struct edge { ll B, T, F, P; };

unsigned MOD = 1234567891;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 10;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), x(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		x[a[i]] = i;
	}
	ll ans = 0;
	while (m--) {
		int b; cin >> b;
		b--;
		int i = x[b];
		ans += i / k + 1;
		if (i == 0) continue;
		int _b = a[i - 1];
		swap(a[i], a[i - 1]);
		x[b]--; x[_b]++;
	}
	cout << ans << endl;
}
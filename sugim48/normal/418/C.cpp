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

vector<int> f(int n) {
	vector<int> a(n, 1);
	for (int i = 0; ; i = (i + 1) % n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i] * a[i];
		int rt = sqrt(sum);
		if (rt * rt == sum) return a;
		a[i]++;
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> a = f(n), b = f(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i] * b[j] << ' ';
		cout << endl;
	}
}
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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	vector<bool> x(1000001), y(1000001);
	vector<int> nextnext(1000001);
	for (int i = 0; i < n; i++) {
		x[a[i]] = true; y[b[i]] = true;
		nextnext[a[i]] = b[i];
	}
	int first, second;
	for (int j = 1; j <= 1000000; j++)
		if (x[j] && !y[j]) first = j;
	for (int i = 0; i < n; i++)
		if (a[i] == 0) second = b[i];
	vector< vector<int> > v(2);
	for (int j = first; j != 0; j = nextnext[j])
		v[0].push_back(j);
	for (int j = second; j != 0; j = nextnext[j])
		v[1].push_back(j);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i % 2][i / 2]);
	cout << endl;
}
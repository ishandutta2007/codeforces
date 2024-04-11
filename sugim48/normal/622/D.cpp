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
	vector<int> a(n * 2);
	int x = n / 2, y = (n + 1) / 2;
	for (int i = 0; i < x; i++)
		a[i] = a[x * 2 - 1 - i] = (x - 1 - i) * 2 + 1;
	for (int i = 0; i < y; i++)
		a[x * 2 + i] = a[n * 2 - 2 - i] = (y - 1 - i) * 2;
	for (int i = 0; i < n * 2; i++)
		printf("%d ", n - a[i]);
	cout << endl;
}
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
#include <map>
#include <queue>
#include <random>
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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-8;
int INF = INT_MAX / 2;

int main() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	vector<int> l(n);
	l[0] = 1;
	for (int i = 1; i < n; i++)
		l[i] = min(l[i - 1] + 1, h[i]);
	vector<int> r(n);
	r[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
		r[i] = min(r[i + 1] + 1, h[i]);
	int maxi = 0;
	for (int i = 0; i < n; i++)
		maxi = max(maxi, min(l[i], r[i]));
	cout << maxi << endl;
}
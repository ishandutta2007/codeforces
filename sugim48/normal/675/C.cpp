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
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

ll INF = LLONG_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	vector<ll> b;
	ll x = 0;
	for (int i = 0; i < N; i++) {
		b.push_back(x);
		x += a[i];
	}
	sort(b.begin(), b.end());
	vector<int> c;
	c.push_back(0);
	for (int i = 0; i + 1 < N; i++)
		if (b[i] != b[i + 1])
			c.push_back(i + 1);
	c.push_back(N);
	int ma = 0;
	for (int k = 0; k + 1 < c.size(); k++)
		ma = max(ma, c[k + 1] - c[k]);
	cout << N - ma << endl;
}
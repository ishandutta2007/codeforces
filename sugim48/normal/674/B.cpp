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
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, K; cin >> N >> K;
	if (N == 4 || K < N + 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> u(N);
	for (int i = 0; i < N; i++)
		u[i] = i;
	vector<int> v = u;
	swap(v[0], v[1]);
	swap(v[N - 2], v[N - 1]);
	vector<int> p(N);
	int a, b, c, d; cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	p[0] = a;
	p[N - 1] = b;
	p[1] = c;
	p[N - 2] = d;
	int x = 0;
	for (int i = 2; i < N - 2; i++) {
		for (; x == a || x == b || x == c || x == d; x++);
		p[i] = x++;
	}
	for (int i = 0; i < N; i++)
		cout << p[u[i]] + 1 << ' ';
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << p[v[i]] + 1 << ' ';
	cout << endl;
}
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
#include <random>
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

vector<double> mul(vector<double>& a, vector<double>& b) {
	vector<double> c(128);
	for (int x = 0; x < 128; x++)
		for (int y = 0; y < 128; y++)
			c[x ^ y] += a[x] * b[y];
	return c;
}

int main() {
	int N, M; cin >> N >> M;
	M++;
	vector<double> p(128);
	for (int i = 0; i < M; i++) cin >> p[i];
	vector<double> a(128);
	a[0] = 1;
	for (; N; N /= 2) {
		if (N % 2) a = mul(a, p);
		p = mul(p, p);
	}
	printf("%.10f\n", 1 - a[0]);
}
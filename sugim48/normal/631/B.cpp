#define _USE_MATH_DEFINES
#include <algorithm>
#include <complex>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, M, K; cin >> N >> M >> K;
	vector<i_i> a(N), b(M);
	for (int t = 1; t <= K; t++) {
		int q, z, c; scanf("%d%d%d", &q, &z, &c);
		z--;
		if (q == 1) a[z] = i_i(t, c);
		if (q == 2) b[z] = i_i(t, c);
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			printf("%d ", max(a[y], b[x]).second);
		cout << endl;
	}
}
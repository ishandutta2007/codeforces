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
double EPS = 1e-9;

int main() {
	int N, T; cin >> N >> T;
	vector<vector<double> > a(N, vector<double>(N));
	while (T--) {
		a[0][0] += 1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++) {
				if (a[i][j] < 1) continue;
				double x = a[i][j] - 1;
				a[i][j] = 1;
				if (i + 1 < N) {
					a[i + 1][j] += x / 2;
					a[i + 1][j + 1] += x / 2;
				}
			}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (a[i][j] > 1 - EPS)
				cnt++;
	cout << cnt << endl;
}
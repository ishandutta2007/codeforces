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
	int n, k; cin >> n >> k;
	vector<int> sum(2000001);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum[a]++;
	}
	for (int x = 1; x <= 2000000; x++)
		sum[x] += sum[x - 1];
	for (int d = 1000000; ; d--) {
		int cnt = 0;
		for (int x = d; x <= 1000000; x += d)
			cnt += sum[x + min(d - 1, k)] - sum[x - 1];
		if (cnt >= n) {
			cout << d << endl;
			return 0;
		}
	}
}
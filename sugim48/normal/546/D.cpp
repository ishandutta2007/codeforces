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
	vector<int> c(5000001);
	for (int i = 2; i <= 5000000; i++)
		if (!c[i])
			for (int j = i; j <= 5000000; j += i)
				for (int x = j; x % i == 0; x /= i)
					c[j]++;
	vector<ll> sum(5000001);
	for (int i = 1; i <= 5000000; i++)
		sum[i] = sum[i - 1] + c[i];
	int t; cin >> t;
	while (t--) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%I64d\n", sum[a] - sum[b]);
	}
}
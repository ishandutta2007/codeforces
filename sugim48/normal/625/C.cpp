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
struct edge { int u, v; char c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, k; cin >> n >> k;
	k--; int l = n - k;
	vector<vector<int> > a(n, vector<int>(n));
	for (int i = 0; i < k * n; i++)
		a[i / k][i % k] = i;
	for (int i = k * n; i < n * n; i++)
		a[(i - k * n) / l][k + (i - k * n) % l] = i;
	int sum = 0;
	for (int y = 0; y < n; y++)
		sum += a[y][k] + 1;
	cout << sum << endl;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++)
			printf("%d ", a[y][x] + 1);
		printf("\n");
	}
}
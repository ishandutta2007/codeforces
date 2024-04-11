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

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> b(1000001);
	for (int i = n - 1; i >= 0; i--) {
		b[a[i]] = 1;
		for (int j = a[i] * 2; j <= 1000000; j += a[i])
			if (b[j] && b[j] + 1 > b[a[i]])
				b[a[i]] = b[j] + 1;
	}
	int maxi = 0;
	for (int j = 0; j <= 1000000; j++)
		maxi = max(maxi, b[j]);
	cout << maxi << endl;
}
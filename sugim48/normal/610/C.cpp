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
double EPS = 1e-10;

int a[512][512];

int main() {
	a[0][0] = 1;
	for (int k = 0; k < 9; k++) {
		int n = 1<<k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				a[n + i][j] = a[i][j];
				a[i][n + j] = a[i][j];
				a[n + i][n + j] = -a[i][j];
			}
	}
	int k; cin >> k;
	int n = 1<<k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (a[i][j] == 1 ? '+' : '*');
		cout << endl;
	}
}
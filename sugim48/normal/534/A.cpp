#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
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

int main () {
	int n; cin >> n;
	if (n <= 2) cout << 1 << endl << 1 << endl;
	else if (n == 3) cout << 2 << endl << 1 << ' ' << 3 << endl;
	else if (n == 4) cout << 4 << endl << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << endl;
	else {
		cout << n << endl;
		for (int i = 1; i <= n; i += 2)
			cout << i << ' ';
		for (int i = 2; i <= n; i += 2)
			cout << i << ' ';
		cout << endl;
	}
}
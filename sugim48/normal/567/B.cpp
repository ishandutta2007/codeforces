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

int main() {
	int n; cin >> n;
	int x = 0, maxi = 0, y = 0;
	vector<bool> a(1000001);
	while (n--) {
		string s; int r; cin >> s >> r;
		if (s == "+") {
			x++;
			a[r] = true;
		}
		if (s == "-") {
			x--;
			if (!a[r]) y++;
			a[r] = false;
		}
		maxi = max(maxi, x);
	}
	cout << maxi + y << endl;
}
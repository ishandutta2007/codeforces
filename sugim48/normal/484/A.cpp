#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; double w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	while (n--) {
		ll l, r; cin >> l >> r;
		r++;
		ll ans = 0;
		for (int i = 62; i >= 0; i--) {
			ll x = l & (1LL << i), y = r & (1LL << i);
			if (x == y) ans += x;
			else {
				ans += y - 1;
				break;
			}
		}
		cout << ans << endl;
	}
}
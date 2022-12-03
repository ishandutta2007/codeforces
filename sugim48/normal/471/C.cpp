#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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
struct edge { int u, v; ll w; };

int main() {
	ll n; cin >> n;
	int ans = 0;
	for (ll h = 1; h <= 1000000; h++) {
		ll x = h * 2 + h * (h - 1) / 2 * 3;
		if (n >= x && (n - x) % 3 == 0) ans++;
	}
	cout << ans << endl;
}
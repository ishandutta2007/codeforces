#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
struct edge { int u, v; ll w; };

int main() {
	ll a, b, c; cin >> a >> b >> c;
	vector<ll> ans;
	for (ll s = 1; s <= 81; s++) {
		ll y = 1;
		for (int i = 0; i < a; i++) y *= s;
		ll x = y * b + c;
		if (x <= 0 || x >= 1000000000) continue;
		ll _x = x, sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += _x % 10;
			_x /= 10;
		}
		if (sum == s) ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	int n = ans.size();
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i < n - 1) cout << ' ';
	}
	cout << endl;
}
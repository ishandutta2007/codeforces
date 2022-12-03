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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
	map<ll, ll> ans, m, _m;
	for (int i = 0; i < n; i++) {
		_m.clear();
		_m[a[i]]++;
		ans[a[i]]++;
		for (map<ll, ll>::iterator it = m.begin(); it != m.end(); it++) {
			ll d = gcd(it->first, a[i]);
			_m[d] += it->second;
			ans[d] += it->second;
		}
		swap(m, _m);
	}
	int q; cin >> q;
	while (q--) {
		ll x; scanf("%I64d", &x);
		printf("%I64d\n", ans[x]);
	}
}
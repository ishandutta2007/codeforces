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

void foo(ll k, vector<ll>& a) {
	ll n = a.size();
	ll mb, mc, mf = LLONG_MAX;
	for (int b = 0; b < (1 << n); b++) {
		int cnt = 0; ll f = 0;
		for (int i = 0; i < n; i++)
			if (b & (1 << i)) {
				cnt++;
				f ^= a[i];
			}
		if (cnt > 0 && cnt <= k && f < mf) {
			mb = b;
			mc = cnt;
			mf = f;
		}
	}
	cout << mf << endl;
	cout << mc << endl;
	for (int i = 0; i < n; i++)
		if (mb & (1 << i))
			cout << a[i] << ' ';
	cout << endl;
}

int main() {
	ll l, r, k; cin >> l >> r >> k;
	if (k == 1) {
		cout << l << endl;
		cout << 1 << endl;
		cout << l << endl;
	}
	else if (k == 2) {
		vector<ll> a;
		a.push_back(l); a.push_back(l + 1);
		if (l + 2 <= r) a.push_back(l + 2);
		foo(2, a);
	}
	else if (k == 3) {
		ll x = 1, y = 2, z = 3;
		for (int i = 0; i < 55; i++) {
			if (x >= l && z <= r) {
				cout << 0 << endl;
				cout << 3 << endl;
				cout << x << ' ' << y << ' ' << z << endl;
				return 0;
			}
			x = (x << 1) + 1;
			y = (y << 1) + 1;
			z = z << 1;
		}
		vector<ll> a(3);
		a[0] = l; a[1] = l + 1; a[2] = l + 2;
		foo(3, a);
	}
	else {
		int n = min(8LL, r - l + 1);
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
			a[i] = l + i;
		foo(4, a);
	}
}
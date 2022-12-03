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
	ll n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	sort(b.begin(), b.end());
	if (b[0] == b[n - 1]) cout << 0 << " " << n * (n - 1) / 2 << endl;
	else {
		ll j = 0, k = n - 1;
		while (b[j] == b[0]) j++;
		while (b[k] == b[n - 1]) k--;
		cout << b[n - 1] - b[0] << " " << j * (n - 1 - k) << endl;
	}
}
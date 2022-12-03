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

int sum(vector<int>& bit, int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

void add(vector<int>& bit, int i, int x) {
	int n = bit.size() - 1;
	while (i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> fi(n);
	map<int, int> mi;
	for (int i = 0; i < n; i++)
		fi[i] = ++mi[a[i]];
	vector<int> fj(n);
	map<int, int> mj;
	for (int j = n - 1; j >= 0; j--)
		fj[j] = ++mj[a[j]];
	vector<int> bit(n + 1);
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += sum(bit, fi[i] - 1);
		add(bit, fj[i], 1);
	}
	cout << ans << endl;
}
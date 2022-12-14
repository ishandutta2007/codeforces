#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 1000000007;
int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}

const int N = 200005;

set<int> all;

void good(int a, int b) {
	int x = (a + b + 1) / 2, y = a + b - x;
	// b x, a y
	int mx = min(x, b) + min(a, y);
	int mn = 0;
	int tmp = min(y, b);
	b -= tmp, y -= tmp;
	tmp = min(x, a);
	x -= tmp, a -= tmp;
	mn = min(x, b) + min(y, a);
	for (int i = mn; i <= mx; i += 2) all.insert(i);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int a, b;
		cin >> a >> b;
		all.clear();
		good(a, b), good(b, a);
		cout << all.size() << '\n';
		for (int x : all) cout << x << ' ';
		cout << '\n';
	}
}
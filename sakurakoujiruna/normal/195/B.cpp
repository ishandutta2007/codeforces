#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
int p[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	iota(p, p + m, 1);
	sort(p, p + m, [&](int a, int b) {
		if(min(a, m - a + 1) > min(b, m - b + 1)) return true;
		else if(min(a, m - a + 1) < min(b, m - b + 1)) return false;
		return a < b;
	});
	for(int i = 0; i < n; i ++)
		cout << p[i % m] << '\n';
	return 0;
}
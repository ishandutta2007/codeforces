#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;
int c[N], d[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	int x = 1e9L, sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> c[i] >> d[i];
		if(d[i] == 2)
			x = min(x, 1899 - sum);
		sum += c[i];
	}
	bool f = 1;
	for(int i = 1; i <= n; i ++) {
		if(x >= 1900 && d[i] == 2) f = 0;
		if(x <= 1899 && d[i] == 1) f = 0;
		x += c[i];
	}
	if(f) {
		if(x > 1e8L)
			cout << "Infinity\n";
		else
			cout << x << '\n';
	} else
		cout << "Impossible\n";
}
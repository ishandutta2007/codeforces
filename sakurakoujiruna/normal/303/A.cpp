#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	if(n & 1) {
		for(int i = 0; i < n; i ++)
			cout << i << (i == n - 1 ? '\n' : ' ');
		for(int i = 0; i < n; i ++)
			cout << i << (i == n - 1 ? '\n' : ' ');
		for(int i = 0; i < n; i ++)
			cout << 2 * i % n << (i == n - 1 ? '\n' : ' ');
	} else
		cout << -1 << '\n';
	return 0;
}
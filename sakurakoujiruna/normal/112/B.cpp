#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, x, y; cin >> n >> x >> y; n /= 2;
	if((x - (n & 1)) / 2 * 2 + (n & 1) == n &&
		(y - (n & 1)) / 2 * 2 + (n & 1) == n)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;	
}
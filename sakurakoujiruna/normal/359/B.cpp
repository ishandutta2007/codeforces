#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= k; i ++)
		cout << 2 * i << ' ' << 2 * i - 1 << ' ';
	for(int i = 2 * k + 1; i <= 2 * n; i ++)
		cout << i << ' ';
	cout << '\n';
	return 0;
}
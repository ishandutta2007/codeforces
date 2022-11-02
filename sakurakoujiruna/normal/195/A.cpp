#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int a, b, c; cin >> a >> b >> c;
	int pre = (a - b) * c;
	int ans = pre / b + (pre % b == 0 ? 0 : 1);
	cout << ans << '\n';
	return 0;
}
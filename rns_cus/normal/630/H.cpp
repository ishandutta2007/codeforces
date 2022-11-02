#include <bits/stdc++.h>
using namespace std;

long long n, ans;

int main() {
//	freopen("h.in", "r", stdin);
	cin >> n;
	ans = 1;
	for (int i = 1; i <= 5; i ++) ans *= (n - i + 1);
	cout << ans / 120 * ans << endl;
	return 0;
}
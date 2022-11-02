#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n, ll h) {
	if(n == 0) return 0;
	if(h < (1LL << (n - 1)))
		return solve(n - 1, h ^ ((1LL << (n - 1)) - 1)) + 1;
	return solve(n - 1, h ^ (1LL << (n - 1))) + (1LL << n);
}

int main() {
	ios :: sync_with_stdio(false);
	int n; ll h;
	cin >> n >> h;
	cout << solve(n, h - 1) << '\n';
	return 0;
}
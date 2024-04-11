#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
LL ans;

LL lcm(LL a, LL b) {
	return a * b / __gcd(a, b);
}

LL calc(LL a, LL b, LL c) {
	return lcm(a, lcm(b, c));
}

int main() {
//	freopen("c.in", "r", stdin);
	cin >> n;
    int mx = min(n - 1, 5);
    for (int i = 0; i <= mx; i ++) {
		for (int j = 0; j <= mx; j ++) {
			for (int k = 0; k <= mx; k ++) ans = max(ans, calc(n - i, n - j, n - k));
		}
    }
    cout << ans << endl;
}
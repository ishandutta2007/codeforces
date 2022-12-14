#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int _, m, s, sum, mx, b[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		sum = mx = 0;
		memset(b, 0, sizeof b);
		cin >> m >> s;
		for (int x, i = 1; i <= m; i ++) {
			cin >> x;
			b[x] = 1;
			mx = max(mx, x);
		}
		for (int i = 1; i <= mx; i ++) {
			sum += (b[i]) ? 0 : i;
		}
		if (sum > s) cout << "NO\n";
		else if (sum == s) cout << "YES\n";
		else {
			while (sum < s) sum += (++mx);
			cout << (sum == s ? "YES\n" : "NO\n");
		}
	}
	return 0;	
}
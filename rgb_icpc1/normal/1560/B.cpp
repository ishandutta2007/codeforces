#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N;



int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a < b) swap(a, b);
		int d = (a - b), res;
		int k = d * 2;
		if(c > d) res = c - d;
		else res = c + d;
		if(res == a || res == b || res == c || res > k || res < 1 || a > k || b > k || c > k) cout << "-1\n";
		else cout << res << "\n";
	}

	return 0;

}
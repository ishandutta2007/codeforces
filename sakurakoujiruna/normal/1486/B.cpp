#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 11;
int x[N], y[N];

int main() {
	ios :: sync_with_stdio(0);
	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		for(int i = 1; i <= n; i ++)
			cin >> x[i] >> y[i];
		
		sort(x + 1, x + n + 1);
		sort(y + 1, y + n + 1);
		
		if(n & 1)
			cout << 1 << '\n';
		else
			cout << ll(x[n / 2 + 1] - x[n / 2] + 1) * (y[n / 2 + 1] - y[n / 2] + 1) << '\n';
	}
}
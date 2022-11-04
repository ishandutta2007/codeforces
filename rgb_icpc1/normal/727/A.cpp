#include <bits/stdc++.h>

using namespace std;

long long a, b;
int n, res[40], _res[40];

void dfs(long long u, int se) {
	if (u > b) return ;
	else if (u == b) {
		res[se] = b;
		if (se < n) {
			for (int i = 0; i < se; i ++) res[i] = _res[i];
			n = se + 1;
		}
		return ;
	}
	_res[se] = u;
	dfs(u * 2, se + 1);
	dfs(u * 10 + 1, se + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b;
	n = 40;
	dfs(a, 0);
	
	if (n < 40) {
		cout << "YES" << endl;
		cout << n << endl;
		for (int i = 0; i < n; i ++) cout << res[i] << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
	
	return 0;
}
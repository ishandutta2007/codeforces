#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int x, int y) {
	if (y >= x) return y+1 - x;
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		if (max(v[1], v[2]) >= v[0]) cout << max(v[1], v[2]) - v[0] + 1; else cout << 0; cout << " ";
		if (max(v[0], v[2]) >= v[1]) cout << max(v[0], v[2]) - v[1] + 1; else cout << 0; cout << " ";
		if (max(v[0], v[1]) >= v[2]) cout << max(v[0], v[1]) - v[2] + 1; else cout << 0; cout << "\n";
	}
}
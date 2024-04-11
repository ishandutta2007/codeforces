#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, a, b, k; cin >> n >> a >> b >> k;
	string s; cin >> s; int p = 0;
	vector <int> v;
	for(int i = 0; i <= n; i ++) if(i == n || s[i] == '1') {
		int l = p + 1, r = i;
		p = i + 1;
		if(l > r) continue;
		while(r - l + 1 >= b) {
			v.push_back(l + b - 1);
			l += b;
		}
	}
	cout << v.size() - a + 1 << '\n';
	for(int i = 0; i < v.size() - a + 1; i ++)
		cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
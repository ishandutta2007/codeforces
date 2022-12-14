#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;
string str;
int n, ans;

int main() {
	mp["Tetrahedron"] = 4;
	mp["Cube"] = 6;
	mp["Octahedron"] = 8;
	mp["Dodecahedron"] = 12;
	mp["Icosahedron"] = 20;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> str;
		ans += mp[str];
	}
	cout << ans;
	return 0;
}
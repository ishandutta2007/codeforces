#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
string s[20], t[50];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < m; ++i) cin >> t[i];
	int q;
	cin >> q;
	for (int x; q--;) {
		cin >> x, --x;
		cout << s[x % n] + t[x % m] << endl;
	}
	return 0;
}
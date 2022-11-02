#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m; string s[1009], t[1009];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < m; i++) cin >> t[i];
	int u = 0;
	for (int i = 0; i < n; i++) {
		if (binary_search(t, t + m, s[i])) u++;
	}
	if (n > m) cout << "YES" << endl;
	else if (n < m) cout << "NO" << endl;
	else cout << (u % 2 == 1 ? "YES" : "NO") << endl;
	return 0;
}
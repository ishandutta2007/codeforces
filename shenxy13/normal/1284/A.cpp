#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s[n], t[m];
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < m; ++i) cin >> t[i];
	int q, y;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> y;
		cout << s[(y - 1) % n] << t[(y - 1) % m] << '\n';
	}
	return 0;
}
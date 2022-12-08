#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
map<int, int> m;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, mark, c;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			m.insert({a[i], i});
		}
		mark = n;
		c = 0;
		while (m.size() > 0) {
			auto it = m.end();
			--it;
			for (i = it->second; i < mark; ++i) {
				b[c++] = a[i];
				m.erase(a[i]);
			}
			mark = it->second;
		}
		for (i = 0; i < n; ++i)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}
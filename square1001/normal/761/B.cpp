#include <vector>
#include <iostream>
using namespace std;
int n, m, a[109], b[109];
int main() {
	cin >> n >> m;
	vector<int> p(m), q(m);
	for (int i = 0; i < n; i++) cin >> a[i], p[a[i]]++;
	for (int i = 0; i < n; i++) cin >> b[i], q[b[i]]++;
	bool flag = false;
	for (int i = 0; i < m; i++) {
		if (p == q) flag = true;
		vector<int> r(m);
		for (int j = 0; j < m; j++) r[(j + 1) % m] = q[j];
		q = r;
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}
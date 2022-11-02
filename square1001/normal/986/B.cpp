#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	vector<bool> vis(n);
	int sw = n;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int pos = i;
		while (!vis[pos]) {
			vis[pos] = true;
			pos = p[pos];
		}
		--sw;
	}
	cout << (3 * n % 2 == sw % 2 ? "Petr" : "Um_nik") << endl;
	return 0;
}
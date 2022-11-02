#include <vector>
#include <iostream>
using namespace std;
int n, a[100009], c[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], c[a[i]]++;
	bool f = true;
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		if (c[i] != 0 && c[i] * 2 != n) f = false;
		if (c[i] >= 1) v.push_back(i);
	}
	if (!f) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << v[0] << endl;
		cout << v[1] << endl;
	}
	return 0;
}
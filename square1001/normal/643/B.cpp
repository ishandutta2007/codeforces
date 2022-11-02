#include <vector>
#include <iostream>
using namespace std;
int n, m, a, b, c, d;
int main() {
	cin >> n >> m >> a >> b >> c >> d;
	if (n == 4 || m <= n) cout << -1 << endl;
	else {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && i != c && i != d) v.push_back(i);
		}
		vector<int> w1 = { a, c, d, b }, w2 = { c, a, b, d };
		w1.insert(w1.begin() + 2, v.begin(), v.end());
		w2.insert(w2.begin() + 2, v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << w1[i];
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << w2[i];
		}
		cout << endl;
	}
	return 0;
}
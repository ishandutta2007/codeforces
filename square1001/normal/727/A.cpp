#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, x[109];
int main() {
	cin >> a >> b;
	vector<int> x; x.push_back(b);
	while (a < x.back()) {
		if (x.back() % 10 == 1) x.push_back(x.back() / 10);
		else if (x.back() % 2 == 0) x.push_back(x.back() / 2);
		else break;
	}
	if (a != x.back()) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << x.size() << endl;
		reverse(x.begin(), x.end());
		for (int i = 0; i < x.size(); i++) {
			if (i) cout << ' ';
			cout << x[i];
		}
		cout << endl;
	}
	return 0;
}
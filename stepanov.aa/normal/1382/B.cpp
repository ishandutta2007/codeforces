#include <iostream>
#include <vector>

using namespace std;


bool who_wins(vector<int> &a, int i = 0) {
	if (i == a.size() - 1 || a[i] > 1) {
		return true;
	}
	else {
		return !who_wins(a, i + 1);
	}
}


int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (who_wins(a)) {
			cout << "First" << endl;
		}
		else {
			cout << "Second" << endl;
		}
	}
	return 0;
}
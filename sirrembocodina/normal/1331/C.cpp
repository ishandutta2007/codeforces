#include "bits/stdc++.h"

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < 6; ++i) {
		a.push_back(n % 2);
		n /= 2;
	}
	vector<int> b = {a[4], a[1], a[3], a[2], a[0], a[5]};
	for (int i = 5; i >= 0; --i) {
		n *= 2;
		n += b[i];
	}
	cout << n << endl;
}
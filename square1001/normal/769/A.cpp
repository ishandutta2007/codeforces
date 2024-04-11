#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << (*min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end())) / 2 << endl;
	return 0;
}
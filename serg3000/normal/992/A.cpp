#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>b(1000000);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i] + 100000]++;
	}
	int cnt = 0;
	for (int i = 0; i < 1000000; i++) {
		if (i != 100000) {
			if (b[i] != 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
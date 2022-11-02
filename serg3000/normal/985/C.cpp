#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, k, l;
	cin >> n >> k >> l;
	int n2 = n;
	vector<int>a(n * k);
	vector<int>b(0);
	for (int i = 0; i < n * k; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int z = -1;
	for (int i = 0; i < n * k; i++) {
		if (a[i] > a[0] + l) {
			z = i;
			break;
		}
	}
	if (z == -1) {
		z = n * k;
	}
	if (z < n) {
		cout << 0;
		return 0;
	}
	z = z - 1;
	while (z != -1){
		if (n * k - z >= k) {
			b.push_back(a[z]);
			n -= 1;
			z -= 1;
		}
		else {
			z -= 1;
		}
	}
	long long summ = 0;
	for (int i = 0; i < n2; i++) {
		summ += b[i];
	}
	cout << summ;
	return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[109];
int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	cout << n * *max_element(a, a + n) - sum << endl;
	return 0;
}
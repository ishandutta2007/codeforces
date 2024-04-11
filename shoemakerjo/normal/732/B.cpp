#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	int extra = 0;
	for (int i = 0; i < n-1; i++) {
		if (k > a[i]+a[i+1]) {
			extra += k - (a[i]+a[i+1]);

			a[i+1] += k - (a[i]+a[i+1]);
		}
	}
	cout << extra << endl;
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	// cin >> n;
}
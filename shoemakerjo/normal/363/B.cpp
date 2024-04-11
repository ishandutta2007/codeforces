#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int ans = 0;
	int spot = 0;
	for (int i = 0; i < k; i++) {
		ans+=h[i];
	}
	int rec = ans;
	for (int j = 1; j <= n-k; j++) {
		rec -= h[j-1];
		rec+=h[j+k-1];
		if (rec < ans) {
			ans = rec;
			spot = j;
		}
	}
	cout << spot+1 << endl;
	// cin >> n;
}
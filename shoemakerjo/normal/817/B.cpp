#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int mins[3];
	int big = 2000000000;
	mins[0] = big;
	mins[1] = big;
	mins[2] = big;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == mins[0] || a[i] == mins[1]) continue;
		if (a[i] < mins[0]) {
			mins[2] = mins[1];
			mins[1] = mins[0];
			mins[0] = a[i];
		}
		else if (a[i]  < mins[1]) {
			mins[2] = mins[1];
			mins[1] = a[i];
		}
		else if (a[i] < mins[2]) {
			mins[2] = a[i];
		}
	}
	long long n1 = 0, n2 = 0, n3 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mins[0]) n1++;
		if (a[i] == mins[1]) n2++;
		if (a[i] == mins[2]) n3++;
	}
	long long ans = 0;
	if (n1 >= 3) {
		ans = n1*(n1-1)*(n1-2)/6;
	}
	else if (n1+n2 >= 3) {
		if (n1 == 2) {
			ans = n2;
		}
		else ans = n2*(n2-1)/2;
	}
	else ans = n1*n2*n3;
	// cout << n1 << " " << n2 << " " << n3 << endl;
	// cout << mins[0] << " " << mins[1] << " " << mins[2] << endl;
	cout << ans << endl;
	// cin >> n;
}
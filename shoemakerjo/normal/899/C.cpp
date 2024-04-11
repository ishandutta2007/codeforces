#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n% 4 == 0) {
		cout << 0 << endl;
		cout << n/2 << " ";
		for (int i = 1; i <= n/2; i+= 2) {
			cout << i << " ";
		}
		for (int i = n; i > n/2; i-= 2) {
			cout << i << " ";
		}
		cout << endl;
	}
	if (n%4 == 1) {
		cout << 1 << endl;
		cout << n/2 << " ";
		for (int i = 2; i <= (n+1)/2; i+= 2) {
			cout << i << " ";
		}
		for (int i = n; i > (n+1)/2; i-=2) {
			cout << i << " ";
		}
		cout << endl;
	}
	if (n% 4 == 2) {
		cout << 1 << endl;
		cout << n/2 << " ";
		cout << 1 << " ";
		for (int i = 3; i <= (3+n)/2; i += 2) {
			cout << i << " ";
		}
		for (int i = n; i > (3+n)/2; i -= 2) {
			cout << i << " ";
		}
		cout << endl;
	}
	if (n%4 == 3) {
		cout << 0 << endl;
		cout << n/2 << " ";
		cout << n << " ";
		for (int i = 1; i < n/2; i+= 2) {
			cout << i << " ";
		}
		for (int i = n-1; i > n/2+1; i-=2) {
			cout << i << " ";
		}
		cout << endl;
	}
	cin >> n;
}
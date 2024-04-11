#include <bits/stdc++.h>
using namespace std;
int n, cnt1, cnt2;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j) cout << ' ';
			if(abs(i - n / 2) + abs(j - n / 2) <= n / 2) {
				cout << cnt1++ * 2 + 1;
			}
			else {
				cout << cnt2++ * 2 + 2;
			}
		}
		cout << endl;
	}
	return 0;
}
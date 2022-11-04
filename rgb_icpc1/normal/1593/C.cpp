#include <bits/stdc++.h>
#define MX 400005

using namespace std;

int n, k;
int x[MX], rlt;

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x[i];
		}
		sort (x, x + k);
		int sum = 0;
		rlt = k;
		for (int i = k - 1; i >= 0; i--) {
			sum += (n - x[i]);
			if (sum >= n) {
				rlt = (k - 1 - i);
				break;
			}
		}
		cout << rlt << endl;
	}
	
}
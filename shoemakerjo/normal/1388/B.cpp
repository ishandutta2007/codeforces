#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int nrem = n/4;
		if (n%4 != 0) {
			nrem++;
		}
		for (int i = 0; i < n-nrem; i++) {
			cout << 9;
		}
		for (int i = 0; i < nrem; i++) {
			cout << 8;
		}
		cout << endl;

	}
}
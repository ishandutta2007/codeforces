#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int t;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n < 31) {
			cout << "NO" << endl;
			continue;
		}
		if (n == 36 || n == 40 || n == 44) {
			cout << "YES" << endl;
			cout << 6 << " " << 10 << " " << 15 << " " << n-31 << endl;
		}
		
		else {
			cout << "YES" << endl;
			cout << 6 << " " << 10 << " " << 14 << " " << n-30 << endl;
		}

	}
}
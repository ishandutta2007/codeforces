//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		while (a[i] % 3 == 0) a[i] /= 3;
		while (a[i] % 2 == 0) a[i] /= 2;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i-1]) {
			cout << "No\n";
			return 0;
		}		
	}
	cout << "Yes\n";
	return 0;
}
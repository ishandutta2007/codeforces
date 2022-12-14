//In the name of God
#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
	int n; cin >> n;
	if(n == 2) {
		cout << -1 << '\n';
		return 0;
	}
	a[0] = 2 * 97;
	a[n-1] = 3 * 97;
	for(int i = 1; i < n - 1;i++) a[i] = 6 * i;
	for(int i = 0; i < n;i++) cout << a[i] << '\n';
}
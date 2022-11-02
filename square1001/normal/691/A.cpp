#include <bits/stdc++.h>
using namespace std;
int n, a[1009];
int main() {
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) cin >> a[i], sum += a[i] ^ 1;
	cout << ((n != 1 && sum == 1) || (n == 1 && sum == 0) ? "YES" : "NO") << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, x, a, c[131111];
int main() {
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> a, c[a]++;
	long long ret = 0;
	for(int i = 0; i <= 100000; i++) {
		if(x != 0) ret += 1LL * c[i] * c[i ^ x];
		else ret += 1LL * c[i] * (c[i] - 1);
	}
	cout << ret / 2 << endl;
	return 0;
}
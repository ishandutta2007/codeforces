#include <bits/stdc++.h>
using namespace std;
int m, b;
int main() {
	cin >> m >> b;
	long long ret = 0;
	for(int i = 0; i <= b; i++) {
		int x = m * (b - i), y = i;
		ret = max(ret, 1LL * (x + y) * (x + 1) * (y + 1));
	}
	cout << ret / 2 << endl;
	return 0;
}
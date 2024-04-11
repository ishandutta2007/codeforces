#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
	cin >> n >> a;
	int ret = 1012345678, pos = -1;
	for(int i = 2; i < n; i++) {
		int z = (i - 1) * 180, r = abs(a * n - z);
		if(ret > r) ret = r, pos = i;
	}
	cout << 2 << ' ' << 1 << ' ' << pos + 1 << endl;
	return 0;
}
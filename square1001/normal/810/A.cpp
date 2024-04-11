#include <bits/stdc++.h>
using namespace std;
int n, k, a, s;
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a, s += a;
	for(int i = 0; ; i++) {
		if(s * 2 >= (n + i) * (k * 2 - 1)) {
			cout << i << endl;
			break;
		}
		s += k;
	}
	return 0;
}
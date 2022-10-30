#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	long long ret = 0;
	for(long long i = 0; i <= min(a, b); i++) {
		ret = max(ret, i * 32 + min({a - i, c, d}) * 256);
	}
	cout << ret << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	for(int i = 0; i <= 100000; i++) {
		int t = b + i * a;
		if(t >= d && (t - d) % c == 0) {
			cout << t << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
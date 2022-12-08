#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int a, b;
	while (T--) {
		cin >> a >> b;
		if (a*2 <= b) {
			cout << a << " " << 2*a << endl;
		}
	}
}
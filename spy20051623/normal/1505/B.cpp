#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n, s = 0;
	cin >> n;
	s = n;
	while (n >= 10) {
		s = 0;
		while (n) {
			s += n % 10;
			n /= 10;
		}
		n = s;
	}
	cout << s << endl;
	return 0;
}
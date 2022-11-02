#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
ll r, x; int q; string s;
int main() {
	cin >> r >> q;
	while (q--) {
		cin >> x >> s;
		int d = 0;
		while (!(x & (1LL << d))) d++;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'U' && (r + 1) != x * 2) {
				if (x & (1LL << (d + 1))) x -= 1LL << d;
				else x += 1LL << d;
				d++;
			}
			if (s[i] == 'R' && d >= 1) x += 1LL << (--d);
			if (s[i] == 'L' && d >= 1) x -= 1LL << (--d);
		}
		cout << x << endl;
	}
	return 0;
}
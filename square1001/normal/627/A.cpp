#include <iostream>
using namespace std;
long long s, x;
int main() {
	cin >> s >> x;
	if (s < x || (s - x) % 2 == 1) cout << 0 << endl;
	else {
		long long b = (s - x) / 2;
		if (b & x) cout << 0 << endl;
		else {
			s -= b;
			long long ret = (s > x ? 1 : 0);
			for (int i = 49; i >= 0; i--) {
				if (s > 1LL << i && (x & (1LL << i))) {
					int cnt = 0;
					for (int j = 0; j < i; j++) {
						if (x & (1LL << j)) cnt++;
					}
					ret += 1LL << cnt;
					s -= 1LL << i;
				}
			}
			cout << ret << endl;
		}
	}
	return 0;
}
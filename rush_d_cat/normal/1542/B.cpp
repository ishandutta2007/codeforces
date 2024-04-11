#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
ll n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> a >> b;
		ll tmp = 1;
		if (n % b == 1 % b) {
			cout << "Yes" << endl; continue;
		}

		bool ok = false;
		if (a > 1) {
			while (tmp <= n) {
				if ((n - tmp) % b == 0) {
					ok = true; break;
				}
				if (tmp > (n + a - 1) / a) break;
				tmp = tmp * a;
			}
		}
		cout << (ok?"Yes":"No") << endl;
	}
}
/*
a(a(1+k[1]b)+k2b)+k3b
*/
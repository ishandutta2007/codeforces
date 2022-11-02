#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		int c = 0;
		
		for (int n = 1; n < 50000; n++) {
			long long l = 0;
			long long r = n + 1;
			while (r - l > 1) {
				long long m = (l + r) / 2;
				if ((n * n - (n / m) * (n / m) > x)) {
					r = m;
				}
				else {
					l = m;
				}
			}
			if ((n * n - (n / l) * (n / l)) == x) {
				cout << n << " " << l << '\n';
				c = -1;
				break;
			}
		}
		if (c == 0) {
			cout << -1 << '\n';
			
		}
		c = 0;
	}
	
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int pn = n, pm = m;
	int g1 = gcd(n, k);
	n /= g1;
	k /= g1;
	int g2 = gcd(m, k);
	m /= g2;
	k /= g2;
	if (k >= 3) {
		cout << "NO" << endl;
	}
	else if (k == 2) {
		cout << "YES" << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << n << ' ' << 0 << endl;
		cout << n << ' ' << m << endl;
	}
	else {
		if (n * 2 <= pn) n *= 2;
		else m *= 2;
		cout << "YES" << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << n << ' ' << 0 << endl;
		cout << n << ' ' << m << endl;
	}
	return 0;
}
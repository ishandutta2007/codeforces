#include <iostream>

using namespace std;
int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a==b) return a;
	if (a < b) {
		return gcd(a, b-a*(b/a));
	}
	else {
		return gcd(a-b*(a/b), b);

	}
}
int main() {
	int n, m, z;
	cin >> n >> m >> z;
	int lcm = n*m/gcd(n,m);
	cout << z/lcm << endl;
	// cin >> n;
}
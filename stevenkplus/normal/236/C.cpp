#include <iostream>

using namespace std;
typedef long long ll;

ll f(ll x) {
	if (x <= 2) return x;
	if (x % 2 == 1) return x * (x - 1) * (x - 2);
	else {
		if (x % 3 != 0) {
			return x * (x - 1) * (x - 3);
		}
		else {
			return f(x - 1);
		}
	}
}

int main() {
	int x;
	cin >> x;
	cout << f(x) << endl;
}
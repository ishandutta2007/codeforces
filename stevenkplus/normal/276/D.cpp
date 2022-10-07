#include <iostream>

using namespace std;

typedef long long ll;

ll A, B;

int main() {
	cin >> A >> B;
	ll num = 1;
	while (A / num != B / num) {
		num *= 2;
	}
	cout << num - 1 << "\n";
	return 0;
}
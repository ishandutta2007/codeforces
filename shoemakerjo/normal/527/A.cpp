#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long count = 0;
	while (a!=b) {
		if (a == 0 || b == 0) break;
		if (a < b) {
			count += b/a;
			b = b%a;
		}
		else {
			count += a/b;
			a = a%b;
		}
	}
	if (a > 0 && a == b) count++;
	cout << count << endl;
	// cin >> a;
}
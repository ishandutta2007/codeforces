#include <iostream>
using namespace std;
int n, a, b, p, q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) p++;
		if (a < b) q++;
	}
	if (p > q) cout << "Mishka" << endl;
	else if (p < q) cout << "Chris" << endl;
	else cout << "Friendship is magic!^^" << endl;
	return 0;
}
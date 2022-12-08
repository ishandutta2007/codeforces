#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, s;
	cin >> a >> b >> s;
	a = abs(a);
	b = abs(b);
	if ((a+b)%2 == (s%2) && (a+b) <= s) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}
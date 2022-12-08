#include <iostream>

using namespace std;

int main() {
	int n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	int sum = n1+n2+n3+n4+n5;
	if (sum%5!=0) {
		cout << -1 << endl;
	}
	else {
		if (sum/5 == 0) {
			cout << -1 << endl;
		}
		else cout << sum/5 << endl;

	}
}
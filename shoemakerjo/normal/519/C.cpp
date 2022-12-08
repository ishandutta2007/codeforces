#include <iostream>

using namespace std;

int main() {
	int n, m;
	int amount = 0;
	cin >> n >> m;
	while (true) {
		if (n==0 || m== 0 || (n < 2 && m < 2)) break;
		amount++;
		if (n > m) {
			n-=2;
			m--;
		}
		else {
			n--;
			m-=2;
		}
	}
	cout << amount << endl;
	// cin >> n;
}
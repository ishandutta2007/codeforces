#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n==1) cout << 1 << endl;
	else if (m > n/2 && m!= 1) {
		cout << m-1 << endl;
	}
	else cout << m+1 << endl;
	// cin >> n;
}
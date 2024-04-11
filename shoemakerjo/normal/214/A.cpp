#include <iostream>

using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (i*i > n) break;
		int b = n-i*i;
		if (b*b+i == m) count++;
	}
	cout << count << endl;
	// cin >> n;
}
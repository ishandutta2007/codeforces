#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		if (x%i==0 && x/i <= n) count++;
	}
	cout << count << endl;
}
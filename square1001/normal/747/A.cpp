#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	int ret = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) ret = i;
	}
	cout << ret << ' ' << n / ret << endl;
	return 0;
}
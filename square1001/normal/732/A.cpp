#include <iostream>
using namespace std;
int n, r;
int main() {
	cin >> n >> r;
	for (int i = 1; ; i++) {
		if (n * i % 10 == r || n * i % 10 == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
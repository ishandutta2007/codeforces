#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << -1 << endl;
	} else {
		for (int i = 1; i <= n; i += 2) {
			cout << i + 1 << " " << i << " ";
		}
	}
	return 0;
}
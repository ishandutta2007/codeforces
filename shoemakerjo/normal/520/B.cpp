#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if (m < n) {
		cout << n-m << endl;
	}
	else {
		int curm = m;
		int turns = 0;
		while (curm > n) {
			if (curm%2 == 0) {
				curm = curm/2;
				turns++;
			}
			else {
				curm = curm/2 + 1;
				turns+=2;
			}
		}
		turns += n-curm;
		cout << turns << endl;
	}
	// cin >> n;
}
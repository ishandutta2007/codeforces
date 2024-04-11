#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int sd(int x) { return x == 0 ? 0 : sd(x / 10) + x % 10; }
int n;
int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 0; ; i++) {
		if (sd(i) == 10) {
			cnt++;
			if (cnt == n) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
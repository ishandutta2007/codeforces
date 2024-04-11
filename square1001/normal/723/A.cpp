#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	int ret = 999999999;
	for (int i = 0; i <= 100; i++) {
		ret = min(ret, abs(i - a) + abs(i - b) + abs(i - c));
	}
	cout << ret << endl;
	return 0;
}
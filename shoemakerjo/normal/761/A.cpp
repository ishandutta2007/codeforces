#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (abs(a-b) <= 1 && !(a== 0 &&  b== 0)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}
#include <iostream>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int fin = a+b;
	while (fin < 0) fin+=n;
	fin = fin%n;
	if (fin == 0) fin+=n;
	cout << fin << endl;
	// cin >> n;
}
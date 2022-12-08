#include <iostream>

using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	int a;
	int w = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		w++;
		if (a > h) w++;
	}
	cout << w << endl;
}
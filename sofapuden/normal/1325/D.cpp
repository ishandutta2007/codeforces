#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;


int main() {
	unsigned long long x, y;
	cin >> x >> y;

	if ((x + y) % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}

	if (x == 0 && y == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (y > x) {
		unsigned long long c = ((y - x) / 2 + x) ^ ((y - x) / 2);
		if (c == x) {
			cout << 2 << "\n" << ((y - x) / 2 + x) << " " << ((y - x) / 2) << "\n";
			return 0;
		}
		else {
			cout << 3 << "\n" << ((y - x) / 2) << " " << ((y - x) / 2) << " " << x << "\n";
		}
	}
	else if (x == y) {
		cout << 1 << "\n" << y << "\n";
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}
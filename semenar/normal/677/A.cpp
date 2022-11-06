#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, h;
	cin >> n >> h;
	int w = n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > h) w++;
	}
	cout << w << endl;
	return 0;
}
#include <iostream>

using namespace std;

int main() {
	int last = -1;
	int rounds = -1;
	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		int cur = a/m;
		if (a%m != 0) cur++;
		if (cur >= rounds) {
			rounds = cur;
			last = i;
		}

	}
	cout << last << endl;
	// cin >> n;
}
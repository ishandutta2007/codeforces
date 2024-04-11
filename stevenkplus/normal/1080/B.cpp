#include <iostream>
#include <math.h>

using namespace std;

int val(int i) {
	if (i == 0) {
		return 0;
	} else if (i % 2) {
		return ((i - 1) / 2) - i;
	} else {
		return i / 2;
	}
}

int main() {
	int q;
	cin >> q;
	for (int c = 0; c < q; c++) {
		int l, r;
		cin >> l >> r;
		cout << val(r) - val(l-1) << endl;
	}
	return 0;
}
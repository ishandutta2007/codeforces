#include <bits/stdc++.h>
using namespace std;
int x[200005], y[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int a, b, k;
	cin >> a >> b >> k;
	if (b < 2) {
		if (k == 0) {
			cout << "Yes" << endl;
			cout << 1;
			for (int i = 0; i < a; ++i)
				cout << 0;
			cout << endl;
			cout << 1;
			for (int i = 0; i < a; ++i)
				cout << 0;
			cout << endl;
		} else
			cout << "No" << endl;
	} else if (a == 0) {
		if (k == 0) {
			cout << "Yes" << endl;
			for (int i = 0; i < b; ++i)
				cout << 1;
			cout << endl;
			for (int i = 0; i < b; ++i)
				cout << 1;
			cout << endl;
		} else
			cout << "No" << endl;
	} else {
		if (a + b - 2 < k)
			cout << "No" << endl;
		else if (k == 0) {
			cout << "Yes" << endl;
			for (int i = 0; i < b; ++i)
				cout << 1;
			for (int i = 0; i < a; ++i)
				cout << 0;
			cout << endl;
			for (int i = 0; i < b; ++i)
				cout << 1;
			for (int i = 0; i < a; ++i)
				cout << 0;
			cout << endl;
		} else {
			cout << "Yes" << endl;
			x[0] = x[1] = 1;
			y[0] = y[k + 1] = 1;
			x[k + 1] = y[1] = 0;
			a--;
			b -= 2;
			int i = 2;
			while (b && i < k + 1) {
				x[i] = y[i] = 1;
				--b;
				++i;
			}
			while (i < k + 1) {
				x[i] = y[i] = 0;
				--a;
				++i;
			}
			i = k + 2;
			while (b) {
				x[i] = y[i] = 1;
				--b;
				++i;
			}
			while (a) {
				x[i] = y[i] = 0;
				--a;
				++i;
			}
			for (int j = 0; j < i; ++j)
				cout << x[j];
			cout << endl;
			for (int j = 0; j < i; ++j)
				cout << y[j];
			cout << endl;
		}
	}
	return 0;
}
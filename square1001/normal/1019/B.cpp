#include <iostream>
using namespace std;
int n, a[100009], b[100009];
int getval(int pos) {
	cout << "? " << pos + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}
void answer(int pos) {
	cout << "! " << pos + 1 << endl;
}
int main() {
	cin >> n;
	if (n % 4 == 2) {
		answer(-2);
	}
	else {
		n /= 2;
		int lf = getval(0), rf = getval(n);
		a[0] = lf, a[n] = rf;
		b[0] = rf, b[n] = lf;
		if (lf == rf) answer(0);
		else {
			int l = 0, r = n;
			while (true) {
				int m = (l + r) >> 1;
				int lv = getval(m), rv = getval(n + m);
				if (lv == rv) {
					answer(m);
					break;
				}
				a[m] = lv; b[m] = rv;
				if ((a[l] < b[l]) != (a[m] < b[m])) {
					r = m;
				}
				else {
					l = m;
				}
			}
		}
	}
	return 0;
}
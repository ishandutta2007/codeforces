#include <iostream>

using namespace std;

int main() {
	int a1, a2, a3, b1, b2, b3, n;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	int asum = a1+a2+a3;
	int bsum = b1+b2+b3;
	int need = 0;
	if (asum%5==0) {
		need += asum/5;
	}
	else {
		need += asum/5 + 1;
	}
	if (bsum % 10 == 0) {
		need += bsum/10;
	}
	else {
		need += bsum/10 + 1;
	}
	if (need <= n) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}
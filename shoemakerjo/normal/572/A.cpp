#include <iostream>

using namespace std;

int main() {
	int na, nb;
	cin >> na >> nb;
	int k, m;
	cin >> k >> m;
	int a[na];
	int b[nb];
	for (int i = 0; i < na; i++) {
		cin >> a[i];
	}
	bool poss = false;
	for (int i = 0; i < nb; i++) {
		cin >> b[i];
		if (b[i] > a[k-1] && nb-i >= m) poss = true;
	}
	if (poss) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> k;

}
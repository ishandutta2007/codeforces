#include <iostream>
using namespace std;
int sgn(int x) { return x < 0 ? -1 : (x == 0 ? 0 : 1); }
int n, a[109];
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	bool f = true;
	for(int i = 2; i < n; i++) {
		if(sgn(a[i - 2] - a[i - 1]) > sgn(a[i - 1] - a[i])) f = false;
	}
	cout << (f ? "YES" : "NO") << endl;
	return 0;
}
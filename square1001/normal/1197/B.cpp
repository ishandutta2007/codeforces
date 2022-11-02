#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	bool ok = true;
	for(int i = 2; i < n; ++i) {
		if(a[i - 2] > a[i - 1] && a[i - 1] < a[i]) {
			ok = false;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}
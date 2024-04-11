#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

int n, a[3010];

int main() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	int ans = 0;
	forn (i, n) {
		forn (j, i) {
			ans += a[j] > a[i];
		}
	}
	if (ans == 0) {
		cout << 0;
		return 0;
	}
	--ans;
	cout << 1 + ans * 2 + bool(ans & 1);
}
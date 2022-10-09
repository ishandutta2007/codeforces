#include <iostream>
#include <cstring>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

int a[100100];
int cnt[100100];
bool notp[100100];

int main() {
	for (int i = 2; i < 100100; ++i) {
		if (notp[i]) {
			continue;
		}
		for (int j = i * 2; j < 100100; j += i) {
			notp[j] = true;
		}
	}
	int n;
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		for (int j = 2; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				++cnt[j];
			}
			while (a[i] % j == 0) {
				a[i] /= j;
			}
		}
		++cnt[a[i]];
	}
	int ans = 1;
	for (int i = 2; i <= 100000; ++i) {
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
	return 0;
}
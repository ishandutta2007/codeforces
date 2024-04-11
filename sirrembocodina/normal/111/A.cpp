#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(a) a.begin(), a.end()

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	if (y < n) {
		cout << -1;
		return 0;
	}
	if (n - 1 + (y - n + 1) * (y - n + 1) < x) {
		cout << -1;
		return 0;
	}
	forn (i, n - 1) {
		cout << 1 << endl;
	}
	cout << y - n + 1;
}
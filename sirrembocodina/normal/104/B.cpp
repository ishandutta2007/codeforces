#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(a) a.begin(), a.end()

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		ans += (x - 1) * (i + 1);
	}
	cout << ans + n;
}
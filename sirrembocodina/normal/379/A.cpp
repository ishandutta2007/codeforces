#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;

int main() {
	int a, b;
	cin >> a >> b;
	int c = 0, ans = 0;
	while (a) {
		ans += a;
		c += a;
		a = c / b;
		c %= b;
	}
	cout << ans;
}
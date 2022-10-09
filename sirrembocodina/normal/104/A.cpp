#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(a) a.begin(), a.end()

int main() {
	int n;
	cin >> n;
	if (n <= 10 || n > 21) {
		cout << 0;
		return 0;
	}
	n -= 10;
	if (n == 10) {
		cout << 15;
	} else {
		cout << 4;
	}
}
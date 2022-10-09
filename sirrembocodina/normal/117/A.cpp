#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forab(i, a, b) for (int i = a; i < int(b); i++)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define fs first
#define sc second

int m;

int when(int a, int b) {
	b--;
	a = a % (m * 2 - 2);
	if (a < m - 1) {
		if (a <= b) {
			return b - a;
		}
		return m - 1 - a + m - 1 - b;
	}
	a = 2 * m - 2 - a;
	if (a >= b) {
		return a - b;
	}
	return a + b;
}

int main() {
	int n;
	cin >> n >> m;
	forn (i, n) {
		int a, b, t;
		cin >> a >> b >> t;
		if (a == b) {
			cout << t << endl;
		} else {
//			cout << when(t, a) << " " << when(t + when(t, a), b) << endl;
			cout << when(t, a) + when(t + when(t, a), b) + t << endl;
		}
    }
}
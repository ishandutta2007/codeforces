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

int nod(int a, int b) {
	return (a ? nod(b % a, a) : b);
}

int main() {
	int n, m, k, t = 0;
	cin >> n >> m >> k;
	while (k) {
		int h;
		if (t) {
			h = nod(k, m);
		} else {
			h = nod(k, n);
		}
		k -= h;
		t = 1 - t;
	}
	cout << 1 - t;
}
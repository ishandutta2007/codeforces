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

int main() {
	int n;
	cin >> n;
	int k = 0, ans = 0;
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		k -= x;
		k += y;
		ans = max(ans, k);
	}
	cout << ans;
}
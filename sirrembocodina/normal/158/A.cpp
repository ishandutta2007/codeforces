#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define forn(i, n) for (int64 i = 0; i < int64(n); i++)
#define forab(i, a, b) for (int64 i = a; i < int64(b); i++)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;

int main() {
	int n, k;
	cin >> n >> k;
	k--;
	vector<int> a(200, 0);
	int y;
	forn (i, n) {
		int x;
		cin >> x;
		a[x]++;
		if (i == k) {
			y = x;
		}
	}
	int ans = 0;
	forab (i, max(y, 1), 200) {
		ans += a[i];
	}
	cout << ans;
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forab(i, a, b) for (int i = a; i < int(b); i++)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int ans = m;
	forab (i, -m, n) {
		int cur = max(0, -i) + max(0, i + m - n);
		forab (j, max(0, i), min(n, i + m)) {
			cur += s[j] != t[j - i];
		}
		ans = min(ans, cur);
	}
	cout << ans;
}
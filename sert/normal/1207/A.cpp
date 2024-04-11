#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int b, p, f, h, c;
	cin >> b >> p >> f >> h >> c;
	if (c > h) {
		swap(c, h);
		swap(p, f);
	}
	int t1 = min(b / 2, p);
	int t2 = min(b / 2 - t1, f);
	cout << t1 * h + t2 * c << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
#ifdef MADE_BY_SERT
	int T = 1;
	for (int i = 1; i < T; i++) solve();	
#endif
}
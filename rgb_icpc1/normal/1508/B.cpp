#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 100005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

bool ok(int n, LL k) {
	if (n >= 61) return 1;
	return ((1ll << (n - 1)) >= k);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		LL k;
		cin >> n >> k;
		if (!ok(n, k)) {
			cout << -1 << endl;
			continue;
		}
		int st = 0, en = 1;
		while (--n) {
			if (ok(n, k)) {
				for (int i = en; i > st; i--) cout << i << ' ';
				st = en;
				en++;
			}
			else {
				k -= (1ll << (n - 1));
				en++;
			}
		}
		for (int i = en; i > st; i--) cout << i << ' ';
		cout << endl;
	}

	return 0;

}
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int mx = 100005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

int a[55], p[55];

int main() {

#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		cin >> n;
		bool flg = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] != i) flg = 1;
		}
		if (flg) {
			int ans = 1;
			if (a[1] == n && a[n] == 1) ans = 3;
			else if (a[1] == 1 || a[n] == n) ans == 1;
			else ans = 2;
			cout << ans << endl;
		}
		else cout << 0 << endl;
	}

	return 0;

}
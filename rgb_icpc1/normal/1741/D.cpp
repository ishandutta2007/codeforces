#include <bits/stdc++.h>
#define MX 264000
using namespace std;

#define endl '\n'

typedef long long LL;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef vector <PII> VPII;
int a[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int tc; cin >> tc;
	while (tc --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		int fg = 0, rlt = 0;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		while (n) {
			for (int i = 1; i <= n; i += 2) {
				if (a[i] == a[i + 1] + 1) {
					rlt ++;
					swap(a[i], a[i + 1]);
				} else if (a[i] != a[i + 1] - 1) {
					fg = 1;
					break;
				}
			}
			if (fg) break;
			n /= 2;
			for (int i = 1; i <= n; i ++) a[i] = a[i * 2] / 2;
		}
		if (fg) cout << -1 << endl;
		else cout << rlt << endl;
	}

	return 0;
}
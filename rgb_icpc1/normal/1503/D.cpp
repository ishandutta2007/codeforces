#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MN = 1000005;
const int M = 998244353;

int a[MN], b[MN], d[MN], f[MN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] <= n && b[i] <= n) flg = 1;
		if (a[i] < b[i]) f[a[i]] = 0, d[a[i]] = b[i];
		else f[b[i]] = 1, d[b[i]] = a[i];
	}
	if (flg) {
		cout << -1 << endl;
		return 0;
	}
	int mn = 2 * n + 1, st = 1, en, rlt = 0;
	for (int i = 1; i <= n; i++) {
		mn = min(mn, d[i]);
		if (mn == 2 * n + 1 - i) {
			en = i;
			int cur = 0, A = 2 * n + 1, B = 2 * n + 1;
			for (int j = st; j <= en; j++) {
				if (A > d[j]) {
					A = d[j];
					cur += f[j];
				}
				else if (B > d[j]) {
					B = d[j];
					cur += (1 - f[j]);
				}
				else {
					flg = 1;
					break;
				}
			}
			if (flg) break;
			rlt += min(cur, en - st + 1 - cur);
			st = en + 1;
		}
	}
	if (flg) {
		cout << -1 << endl;
		return 0;
	}
	cout << rlt << endl;

	return 0;
}
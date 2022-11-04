#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define endl '\n'
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VPII = vector <PII>;
const int MN = 1000005;
int a[MN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc; cin >> Tc;
	while (Tc --) {
		int n; cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		sort(a, a + n);
		int x = 0;
		for (int i = n - 2; i > 0; i --) {
			if (a[i] != a[n - 1]) {
				x = a[i];
				break;
			}
		}
		if (x == 0) x = a[n - 2];
		LL rlt = a[n - 1] - a[0] + a[n - 1] - x;
		int y = 0;
		for (int i = 1; i < n - 1; i ++) {
			if (a[i] != a[0]) {
				y = a[i];
				break;
			}
		}
		if (y == 0) y = a[1];
		chkmax(rlt, a[n - 1] - a[0] + y - a[0]);
		LL cur = 0;
		for (int i = 0; i < n - 2; i ++) {
			chkmax(rlt, a[i + 1] - a[i] + a[n - 1] - a[i]);
		}
		for (int i = n - 1; i > 1; i --) {
			chkmax(rlt, a[i] - a[0] + a[i] - a[i - 1]);
		}
		cout << rlt << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

bool check(int len, int x, int a, int y, int b, int k, vector<int> & p) {
	int all = a * b / __gcd(a, b);
	int ans = 0;
	int cnta = 0, cntb = 0, cntab = 0;
	for (int i = 1; i <= len; i++) {
		if (i % all == 0) {
			cntab++;
		}
		else if (i % a == 0) {
			cnta++;
		}
		else if (i % b == 0) {
			cntb++;
		}
	}
	for (int i = 0; i < cntab; i++)
		ans += p[i] / 100 * (x + y);
	for (int i = cntab; i < cntab + cnta; i++)
		ans += p[i] / 100 * x;
	for (int i = cntab + cnta; i < cntab + cnta + cntb; i++)
		ans += p[i] / 100 * y;
	//cout << "len = " << len << " ans = " << ans << endl;
	return ans >= k;
}

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto &i : p)
		cin >> i;
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	int x, a;
	cin >> x >> a;
	int y, b;
	cin >> y >> b;
	if (x < y) {
		swap(x, y);
		swap(a, b);
	}
	int k;
	cin >> k;
	int l = 0, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (!check(mid, x, a, y, b, k, p))
			l = mid;
		else
			r = mid;
	}
	if (r == n + 1)
		cout << -1 << "\n";
	else
		cout << r << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}
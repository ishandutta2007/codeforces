#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define endl '\n'
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VPII = vector <PII>;

const int MX = 2e5 + 5;

struct BIT {
	int n;
	int v[MX];
	void init(int m) {
		n = m;
		fill_n(v, n + 1, 0);
	}
	void add(int k, int d) {
		for (; k <= n; k += k & -k) v[k] += d;
	}
	int get(int k) {
		int ret = 0;
		for (; k > 0; k -= k & -k) ret += v[k];
		return ret;
	}
} T;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc; cin >> Tc;
	while (Tc --) {
		int n, m, k; cin >> n >> m >> k;
		bool flag = 1;
		T.init(k + 5);
		for (int i = 0; i < k; i ++) {
			int x; cin >> x;
			if (T.get(x - 1) >= n * m - 3) {
				flag = 0;
			}
			T.add(x, 1);
		}
		cout << (flag ? "YA" : "TIDAK") << endl;
	}
	return 0;
}
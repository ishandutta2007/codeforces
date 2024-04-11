#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
#define int ll
const int MOD = 1e3 + 9;
const ld PI = acos(-1);
using cd = complex<double>;

int mul(int a, int b) {
	return a * b % MOD;
}

int binpow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = mul(ans, a);
		}
		a = mul(a, a);
		n >>= 1;
	}
	return ans;
}

int inv(int a) {
	return binpow(a, MOD - 2);
}

int getLog(int n) {
	int ans = 0;
	while (n) {
		ans++;
		n /= 2;
	}
	return ans - 1;
}

void FFT(vector<cd> & a) {
	int n = a.size();
	int LOG = getLog(n);
	//cout << "n = " << n << " LOG = " << LOG << endl;
	assert((1 << LOG) == n);
	vector<cd> w(n);
	for (int i = 0; i < n; i++) {
		w[i] = cd(cos(2 * PI * i / n), sin(2 * PI * i / n));
	}
	vector<int> rev(n);
	rev[0] = 0;
	for (int mask = 1; mask < n; mask++) {
		rev[mask] = (rev[mask >> 1] >> 1) ^ ((mask & 1) << (LOG - 1));
	}
	for (int i = 0; i < n; i++) {
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);
		}
	}
	for (int lvl = 0; lvl < LOG; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < n; st += len << 1) {
			for (int i = 0; i < len; i++) {
				cd x = a[st + i], y = a[st + len + i] * w[i << (LOG - 1 - lvl)];
				a[st + i] = x + y;
				a[st + len + i] = x - y;
			}
		}
	}
}

vector<int> mul(vector<int> a, vector<int> b) {
	int sz = a.size() + b.size();
	while (__builtin_popcount(sz) != 1) {
		sz++;
	}
	/*cout << "a.size() = " << a.size() << " b.size() = " << b.size() << " sz = " << sz << endl;
	cout << "a = " << endl;
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	cout << "b = " << endl;
	for (auto i : b) {
		cout << i << " ";
	}
	cout << endl;*/
	vector<cd> fa(sz), fb(sz);
	for (int i = 0; i < (int)a.size(); i++) {
		fa[i] = a[i];
	}
	for (int i = 0; i < (int)b.size(); i++) {
		fb[i] = b[i];
	}
	/*cout << "fa = " << endl;
	for (auto i : fa) {
		cout << i << " ";
	}
	cout << endl;
	cout << "fb = " << endl;
	for (auto i : fb) {
		cout << i << " ";
	}
	cout << endl;*/
	FFT(fa);
	FFT(fb);
	for (int i = 0; i < sz; i++) {
		fa[i] *= fb[i];
	}
	FFT(fa);
	vector<int> ans(sz);
	for (int i = 0; i < sz; i++) {
		ans[i] = (ll) (fa[i].real() / sz + 0.5) % MOD;
	}
	reverse(ans.begin() + 1, ans.end());
	//while (!ans.empty() && ans.back() == 0) ans.pop_back();
	//for (int i = 0; i < (int)ans.size(); i++) {
	//	ans[i] = mul(ans[i], inv(sz));
	//}
	/*cout << "ans = " << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;*/
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> have(m, vector<int> (1, 1));
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		have[x - 1].push_back(1);
	}
	set<pair<int, int>> sz;
	for (int i = 0; i < m; i++) {
		sz.insert({have[i].size(), i});
	}
	while (sz.size() > 1) {
		int a = sz.begin()->second;
		sz.erase(sz.begin());
		int b = sz.begin()->second;
		sz.erase(sz.begin());
		have[a] = mul(have[a], have[b]);
		sz.insert({have[a].size(), a});
	}
	/*cout << "ans = " << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;*/
	cout << have[sz.begin()->second][k] << endl;
	return 0;
}
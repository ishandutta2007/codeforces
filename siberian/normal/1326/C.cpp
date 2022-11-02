#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, k;
vector<int> p;

void read() {
	cin >> n >> k;
	p.resize(n);
	for (auto &i : p)
		cin >> i;
}

const int MOD = 998244353;

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int ans;

void run() {
	ans = 1;
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] + k > n) {
			if (!flag) {
				flag = true;
				cnt = 1;
			}
			else {
				flag = true;
				ans = mul(ans, cnt);
				cnt = 1;
			}
		}
		else {
			cnt++;
		}
	}
}

ll get(ll x) {
	return x * (x + 1) / 2;
}

void write() {
	ll fans = 0;
	fans += get(n);
	fans -= get(n - k);
	cout << fans << " " << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}
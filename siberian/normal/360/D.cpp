#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
#define int ll
vector<pair<int, int>> getPrimes(int x) {
	vector<pair<int, int>> ans;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		ans.push_back({i, 0});
		while (x % i == 0) {
			x /= i;
			ans[ans.size() - 1].second++;
		}
	}
	if (x > 1) {
		ans.push_back({x, 1});
	}
	return ans;
}

vector<int> getD(int x) {
	vector<int> ans;
	for (int i = 1; i * i <= x; i++) {
		if (x % i) continue;
		ans.push_back(i);
		ans.push_back(x / i);
	}
	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
	return ans;
}

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int binpow(int a, int n, int mod) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ll)ans * a % mod; 
		}
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}

int n, m, p;
vector<int> a;
int h;

vector<int> d;
vector<pair<int, int>> primes;

void init() {
	d = getD(p - 1);
	//primes = getPrimes(p - 1);
	/*cout << "d = " << endl;
	for (auto i : d) {
		cout << i << " ";
	}
	cout << endl;
	cout << "primes = " << endl;
	for (auto i : primes) {
		cout << i.first << " " << i.second << endl;
	}*/
}

int getOrd(int a) {
	//int ans = 0;
	/*int now = a;
	cout << "now = " << now << endl;
	while (now != 1) {
		ans++;
		now *= a;
		now %= p;
		cout << "now = " << now << endl;
	}
	return ans;*/
	/*for (int i = 0; i < (int)primes.size(); i++) {
		int now = a;
		for (int j = 0; j <= (int)primes[i].second; j++) {
			if (binpow(now, p - 1, p) != 1) {
				now *= primes[i].first;
				break;
			}
			now /= primes[i].first;
		}
		ans = gcd(ans, now);
	}
	return ans;*/
	for (auto i : d) {
		if (binpow(a, i, p) == 1) {
			return i;
		}
	}
	assert(false);
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n >> m >> p;
	init();
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		i = (p - 1) / getOrd(i);
		//cout << "i = " << i << endl;
	}
	h = p - 1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		h = gcd(x, h);
	}
	//cout << "h = " << h << endl;
	for (auto &i : a) {
		i = i * gcd(h, (p - 1) / i);
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	/*cout << "a = " << endl;
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;*/
	int ans = 0;
	vector<int> cnt(d.size(), 0);
	for (int i = (int)d.size() - 1; i >= 0; i--) {
		cnt[i] = (p - 1) / d[i];
		for (int j = i + 1; j < (int)d.size(); j++) {
			if (d[j] % d[i] == 0) {
				cnt[i] -= cnt[j];
			}
		}
		for (auto x : a) {
			if (d[i] % x == 0) {
				ans += cnt[i];
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
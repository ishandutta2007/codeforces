#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<pair <int, int> > a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
}

const int MOD = 998244353;

int add(int a, int b) {
	return (a + b) % MOD;
}

int sub(int a, int b) {
	return ((a - b) % MOD + MOD) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

const int MAXN = 3e5 + 10;

int fact[MAXN];

void build() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = mul(fact[i - 1], i);
}

int solve(vector<int> a) {
	sort(a.begin(), a.end());
	int ans = 1;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		while (j < n && a[i] == a[j]) {
			j++;
		}
		int cnt = j - i;
		ans = mul(ans, fact[cnt]);
		i = j - 1;
	}
	return ans;
}

int solve(vector<pair <int, int> > a) {
	sort(a.begin(), a.end());
	int n = a.size();
	for (int i = 1; i < n; i++)
		if (a[i].second < a[i - 1].second)
			return 0; 
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		while (j < n && a[i] == a[j]) {
			j++;
		}
		int cnt = j - i;
		ans = mul(ans, fact[cnt]);
		i = j - 1;
	}
	return ans;
}

int ans;

void run() {
	build();
	ans = fact[n];
	vector<int> b;
	for (auto i : a)
		b.push_back(i.first);
	ans = sub(ans, solve(b));
	b.clear();
	for (auto i : a)
		b.push_back(i.second);
	ans = sub(ans, solve(b));
	ans = add(ans, solve(a));
}

void write() {
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
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
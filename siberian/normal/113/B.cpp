#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

//#define int ll
mt19937 rnd(time(0));
const int MOD1 = 998244353;
const int base1 = 228 + 1337 + rnd() % 1000;

const int MOD2 = 1e9 + 7;
const int base2 = 228 + 1337 + rnd() % 1000;

int add(int a, int b, int MOD) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int sub(int a, int b, int MOD) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b, int MOD) {
	return (ll) a * b % MOD;
}

pair<int, int> get_hash(string s) {
	int ans1 = 0;
	for (auto i : s) {
		ans1 = mul(ans1, base1, MOD1);
		ans1 = add(ans1, i, MOD1);
	}
	int ans2 = 0;
	for (auto i : s) {
		ans2 = mul(ans2, base2, MOD2);
		ans2 = add(ans2, i, MOD2);
	}
	return {ans1, ans2};
}


struct hasher{
	vector<int> pows1, pows2;
	vector<int> hash1, hash2;
	int n;

	hasher() {
	}

	hasher(string s) {
		n = s.size();
		pows1.assign(n + 1, 1);
		hash1.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pows1[i] = mul(pows1[i - 1], base1, MOD1);
			hash1[i] = add(mul(hash1[i - 1], base1, MOD1), s[i - 1], MOD1);
		}
		pows2.assign(n + 1, 1);
		hash2.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pows2[i] = mul(pows2[i - 1], base2, MOD2);
			hash2[i] = add(mul(hash2[i - 1], base2, MOD2), s[i - 1], MOD2);
		}
	}

	pair<int, int> get(int l, int r) {
		return {sub(hash1[r], mul(hash1[l - 1], pows1[r - l + 1], MOD1), MOD1)
		,sub(hash2[r], mul(hash2[l - 1], pows2[r - l + 1], MOD2), MOD2)};
	}
};

string s, a, b;

void solve() {
	cin >> s >> a >> b;
	int n = s.size();
	pair<int, int> L = get_hash(a);
	pair<int, int> R = get_hash(b);
	hasher Hash(s);
	int ans = 0;
	vector<pair<int, int>> have;
	for (int i = 0; i < n; i++) {
		for (int j = i + max(a.size(), b.size()) - 1; j < n; j++) {
			 
			if (Hash.get(i + 1, i + a.size()) != L) continue;
			if (Hash.get(j - b.size() + 2, j + 1) != R) continue;
			have.push_back(Hash.get(i + 1, j + 1));
		}
	}
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	cout << have.size() << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
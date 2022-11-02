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
const int MOD = 998244353;
const int base = 228 + 1337 + rnd() % 1000;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int get_hash(string s) {
	reverse(all(s));
	for (auto &i : s) {
		if (i >= 'A' && i <= 'Z') {
			i = 'a' + i - 'A';
		}
	}
	int ans = 0;
	for (auto i : s) {
		ans = mul(ans, base);
		ans = add(ans, i);
	}
	return ans;
}


struct hasher{
	vector<int> pows;
	vector<int> hash;
	int n;

	hasher() {
	}

	hasher(string s) {
		n = s.size();
		pows.assign(n + 1, 1);
		hash.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pows[i] = mul(pows[i - 1], base);
			hash[i] = add(mul(hash[i - 1], base), s[i - 1]);
		}
	}

	int get(int l, int r) {
		return sub(hash[r], mul(hash[l - 1], pows[r - l + 1]));
	}
};

int n;
string s;
int m;
vector<string> word;
const int MAXN = 1e4 + 10;
unordered_map<int, int> have[MAXN];
vector<int> dp;

void solve() {
	cin >> n >> s;
	hasher Hash(s);
	cin >> m;
	word.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> word[i];
		have[word[i].size()][get_hash(word[i])] = i;
	}
	dp.assign(n + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if (dp[j - 1] == -1) continue;
			int h = Hash.get(j, i);
			if (have[i - j + 1].find(h) == have[i - j + 1].end()) continue;
			dp[i] = have[i - j + 1][h];
		}
	}
	assert(dp[n] != -1);
	vector<string> ans;
	int pos = n;
	while (pos > 0) {
		ans.push_back(word[dp[pos]]);
		pos -= word[dp[pos]].size();
	}
	reverse(all(ans));
	for (auto i: ans)
		cout << i << " ";
	cout << endl;
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
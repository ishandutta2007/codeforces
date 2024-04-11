#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}


vector<char> ans;

void dfs(char v, char p, map<char, bool> & used, map<char, vector<char> > & g) {
	used[v] = true;
	ans.push_back(v);
	for (auto i : g[v]) {
		if (i == p) continue;
		assert(!used[i]);
		dfs(i, v, used, g);
	}
}

void solve() {
	string s;
	cin >> s;
	map<char, vector<char> > g;
	for (int i = 1; i < s.size(); i++) {
		g[s[i]].push_back(s[i - 1]);
		g[s[i - 1]].push_back(s[i]);
	}
	for (auto &i : g) {
		sort(all(i.second));
		i.second.resize(unique(all(i.second)) - i.second.begin());
		if (i.second.size() > 2) {
			cout << "NO\n";
			return;
		}
	}
	map<char, bool> used; 
	for (auto i : g) {
		if (!used[i.first] && i.second.size() == 1) {
			dfs(i.first, '0', used, g);
		}
	}

	/*cout << "ans = " << endl;
	for (auto i : ans)
		cout << i;
	cout << endl;*/

	for (auto i : g) {
		if (!used[i.first]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (auto i : ans)
		cout << i;
	ans.clear();
	for (int i = 0; i < 26; i++) {
		if (!used[i + 'a']) {
			string ans = "";
			ans += i + 'a';
			cout << ans;
		}
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
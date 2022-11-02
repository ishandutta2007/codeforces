#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}



vector<pair <int, char> > erase(vector<pair <int, char> > a, int pos) {
	vector<pair <int, char> > ans;
	for (int i = 0; i < a.size(); i++) {
		if (i != pos) {
			if (ans.empty()) {
				ans.push_back(a[i]);
				continue;
			}
			else {
				if (ans.back().second == a[i].second)
					ans[ans.size() - 1].first += a[i].first;
				else
					ans.push_back(a[i]);
			}
		}
		else if (a[i].first > 1) {
			if (ans.empty()) {
				ans.push_back({a[i].first - 1, a[i].second});
				continue;
			}
			else {
				if (ans.back().second == a[i].second)
					ans[ans.size() - 1].first += a[i].first - 1;
				else
					ans.push_back({a[i].first - 1, a[i].second});
			}
		}
	}
	return ans;
}

pair <bool, set<vector<pair <int, char> > > > make(set<vector<pair <int, char> > > help, int need) {
	set<vector<pair <int, char> > > new_help;
	for (auto i : help) {
		int sz = i.size();
		for (int j = 0; j < sz; j++) {
			new_help.insert(erase(i, j));
			if (new_help.size() >= need) return {true, {}};
		}
	}
	return {false, new_help};
}

vector<pair <int, char> > make(string s) {
	char last = s[0];
	int pos = 0;
	vector<pair <int, char> > ans;
	int n = s.size();
	for (int i = 1; i < n; i++) {
		if (s[i] != last) {
			ans.push_back({i - pos, last});
			last = s[i];
			pos = i;
		}
	}
	ans.push_back({n - pos, last});
	return ans;
}

int n, k;
string s;
void read() {
	cin >> n >> k >> s;
}

int ans = 0;

void run() {
	set<vector<pair <int, char> > > have;
	have.insert(make(s));
	k--;
	int len = 1;
	vector<pair <int, char> > x = {};
	if (k == 0) {
		return;
	}
	while (k && !have.empty()) {
		auto help = make(have, k);
		help.second.erase(x);
		if (help.first) {
			ans += k * len;
			return;
		}
		ans += help.second.size() * len;
		k -= help.second.size();
		have = help.second;

		len++;
	}
	ans = -1;
}

void write() {
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
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> manaker(const string &s) {
    vector<int> man(s.size(), 0);
    int l = 0, r = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            man[i] = min(r - i, man[l + r - i]);
        }
        while (i + man[i] + 1 < n && i - man[i] - 1 >= 0
               && s[i + man[i] + 1] == s[i - man[i] - 1]) {
            man[i]++;
        }
        if (i + man[i] > r) {
            l = i - man[i];
            r = i + man[i];
        }
    }
    return man;
}


void solve() {
	string s;
	cin >> s;
	string rest = "";
	int n = s.size();
	string rs = s;
	reverse(rs.begin(), rs.end());
	int cnt = 0;
	while (cnt < n && s[cnt] == rs[cnt]) {
		++cnt;
	}
	if (cnt >= n / 2) {
		cout << s << "\n";
		return;
	}
	for (int iter = 0; iter < 2; iter++) {
		string t = "";
		for (int i = 0; i < (int) s.size(); i++) {
			t += '#';
			t += s[i];
		}
		auto man_odd = manaker(s), man_even = manaker(t);
		vector <int> res(n, 0);
		for (int i = 0; i < n; i++) {
			if ((i - man_odd[i]) + (i + man_odd[i]) >= n) continue;
			res[i - man_odd[i]] = max(res[i - man_odd[i]], i + man_odd[i]);
		}
		for (int i = 0; i < man_even.size(); i += 2) {
			if ((i - man_even[i]) / 2 + (i + man_even[i] - 1) / 2 >= n) continue;
			res[(i - man_even[i]) / 2] = max(res[(i - man_even[i]) / 2], (i + man_even[i] - 1) / 2);
		}
		for (int i = 0; i < n - 1; i++) {
			res[i + 1] = max(res[i + 1], res[i] - 1);
		}
		int pos = 0;
		int res_size = 0;
		for (int i = 0; i <= cnt; i++) {
			if ((res[i] - i + 1) + 2 * i > res_size) {
				pos = i;
				res_size = (res[i] - i + 1) + 2 * i;
			}
		}
		if (res_size > rest.size()) {
			rest = s.substr(0, pos);
			string rsnow = rest;
			reverse(rsnow.begin(), rsnow.end());
			rest += s.substr(pos, res[pos] - pos + 1);
			rest += rsnow;
		}
		reverse(s.begin(), s.end());
	}

	cout << rest << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}

}
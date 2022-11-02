#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class rollinghash {
private:
	const vector<int> mod = {
		1000000007,
		1000000009,
		1000000021
	};
	string S;
	vector<vector<int> > pw;
	vector<vector<int> > hval;
public:
	rollinghash() : pw(vector<vector<int> >()), hval(vector<vector<int> >()) {};
	rollinghash(string S_) : S(S_) {
		pw.resize(mod.size());
		hval.resize(mod.size());
		for (int i = 0; i < mod.size(); ++i) {
			pw[i].resize(S.length() + 1);
			hval[i].resize(S.length() + 1);
			pw[i][0] = 1;
			for (int j = 0; j < S.length(); ++j) {
				pw[i][j + 1] = 311LL * pw[i][j] % mod[i];
				hval[i][j + 1] = (311LL * hval[i][j] + S[j]) % mod[i];
			}
		}
	}
	vector<int> gethash(int l, int r) {
		vector<int> ans(mod.size());
		for (int i = 0; i < mod.size(); ++i) {
			ans[i] = (hval[i][r] - 1LL * hval[i][l] * pw[i][r - l] % mod[i] + mod[i]) % mod[i];
		}
		return ans;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int zero = 0, one = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') ++zero;
		if (s[i] == '1') ++one;
	}
	rollinghash ht(t);
	int mx = 0;
	for (int i = 1; i < t.size(); ++i) {
		if (ht.gethash(0, i) == ht.gethash(t.size() - i, t.size())) {
			mx = max(mx, i);
		}
	}
	int fzero = 0, fone = 0, dzero = 0, done = 0;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] == '0') {
			++fzero;
			if (i >= mx) ++dzero;
		}
		if (t[i] == '1') {
			++fone;
			if (i >= mx) ++done;
		}
	}
	if (zero < fzero || one < fone) {
		cout << s << '\n';
	}
	else {
		int maxrep = 0;
		while (true) {
			if (fzero + dzero > zero || fone + done > one) {
				break;
			}
			fzero += dzero;
			fone += done;
			++maxrep;
		}
		string ans = t;
		for (int i = 0; i < maxrep; ++i) ans += t.substr(mx);
		ans += string(zero - fzero, '0');
		ans += string(one - fone, '1');
		cout << ans << '\n';
	}
	return 0;
}
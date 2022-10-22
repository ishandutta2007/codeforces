#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
	int n;
	cin >> n;
	vector <string> strs(3);
	vector <int> cnts(3);
	for (int i = 0; i < 3; ++i) {
		cin >> strs[i];
		for (char c : strs[i]) {
			if (c == '0') {
				cnts[i] += 1;
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		int cnta = cnts[i];
		int cntb = cnts[(i + 1) % 3];
		string s = strs[i];
		string t = strs[(i + 1) % 3];
		if (cnta >= n && cntb >= n) {
			if (cntb > cnta) {
				swap(s, t);
				swap(cnta, cntb);
			}
			int j = 0;
			string res = "";
			for (int i = 0; i < 2 * n; ++i) {
				if (t[i] == '0') {
					while (s[j] != '0') {
						res += s[j++];
					}
					res += s[j++];
				} else {
					res += '1';
				}
			}
			while (j < 2 * n) {
				res += s[j++];
			}
			while (res.size() < 3 * n) {
				res += '0';
			}
			cout << res << "\n";
			return;
		}
		if (cnta <= n && cntb <= n) {
			cnta = 2 * n - cnta;
			cntb = 2 * n - cntb;
			if (cntb > cnta) {
				swap(s, t);
				swap(cnta, cntb);
			}
			//cout << cnta << " " << cntb << " " << n << endl;
			//cout << s << " " << t << endl;
			int j = 0;
			string res = "";
			for (int i = 0; i < 2 * n; ++i) {
				if (t[i] == '1') {
					while (s[j] != '1') {
						res += s[j++];
					}
					res += s[j++];
				} else {
					res += '0';
				}
			}
			while (j < 2 * n) {
				res += s[j++];
			}
			while (res.size() < 3 * n) {
				res += '0';
			}
			cout << res << "\n";
			return;
		}
	}
	assert(false);
}


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}
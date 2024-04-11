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
	string s;
	cin >> s;
	int n = s.size();

	vector <int> cnt(26, 0);
	int diff = 0;
	for (char c : s) {
		cnt[c - 'a']++;
		if (cnt[c - 'a'] == 1) {
			++diff;
		}
	}

	if (diff == 1) {
		cout << s << "\n";
		return;
	}

	string t = "";

	for (int i = 0; i < 26; ++i) {
		if (cnt[i] != 1) continue;
		t += (char) (i + 'a');
		--cnt[i];
		for (int i = 0; i < 26; ++i) {
			while (cnt[i]) {
				t += (char) (i + 'a');
				--cnt[i];
			}
		}
		cout << t << "\n";
		return;
	}

	for (int i = 0; i < 26; ++i) {
		if (!cnt[i]) continue;
		t += (char) (i + 'a');
		--cnt[i];
		if (2 * cnt[i] - 1 <= n - 1) {
			while (cnt[i]) {
				t += (char) (i + 'a');
				--cnt[i];
				for (int j = i + 1; j < 26; ++j) {
					if (cnt[j]) {
						t += (char) (j + 'a');
						--cnt[j];
						break;
					}
				}	
			}
			for (int j = 0; j < 26; ++j) {
				while (cnt[j]) {
					t += (char) (j + 'a');
					--cnt[j];
				}
			}
			cout << t << "\n";
			return;
		} else {
			int j;
			for (j = i + 1; j < 26; ++j) {
				if (cnt[j]) break;
			}
			t += (char) (j + 'a');
			--cnt[j];
			if (diff == 2) {
				while (cnt[j]) {
					t += char(j + 'a');
					cnt[j]--;
				}
				while (cnt[i]) {
					t += char(i + 'a');
					cnt[i]--;
				}
			} else {
				int skip = 0;
				for (int k = 0; k < 26; ++k) {
					if (k == j) {
						skip = 1;
						continue;
					}
					while (cnt[k]) {
						t += char(k + 'a');
						--cnt[k];
						if (skip) {
							skip = 2;
							break;
						}
					}
					if (skip == 2) break;
				}
				for (int k = 0; k < 26; ++k) {
					while (cnt[k]) {
						t += char(k + 'a');
						--cnt[k];
					}
				}
			}
			cout << t << "\n";
			return;
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}
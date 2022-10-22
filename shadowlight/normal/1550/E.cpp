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

int n, k;
string s;

bool can(int len) {
	vector <vector<int>> starts(k);
	vector<int> any;

	vector<int> cnt(k, 0);
	for (int i = 0; i < len; ++i) {
		if (s[i] != '?') cnt[s[i] - 'a']++;
	}
	for (int i = len; i <= n; ++i) {
		int tet = -1;
		for (int j = 0; j < k; ++j) {
			if (cnt[j]) {
				if (tet != -1) {
					tet = -2;
					break;
				}
				tet = j;
			}
		}
		if (tet >= 0) {
			starts[tet].pb(i);
		} else if (tet == -1) {
			any.pb(i);
		}
		if (s[i - len] != '?') {
			cnt[s[i - len] - 'a']--;
		}
		if (i < n && s[i] != '?') {
			cnt[s[i] - 'a']++;
		}
	}
	vector <int> dp(1 << k, -1);
	dp[0] = 0;

	for (int mask = 1; mask < (1 << k); ++mask) {
		for (int i = 0; i < k; ++i) {
			if (!(mask & (1 << i))) {
				continue;
			}
			int nmask = mask ^ (1 << i);
			int ppos = dp[nmask];
			if (ppos == -1) continue;

			int nxt = -1;
			int p1 = lower_bound(all(starts[i]), ppos) - starts[i].begin();
			if (p1 != starts[i].size()) {
				nxt = starts[i][p1];
			}
			int p2 = lower_bound(all(any), ppos) - any.begin();
			if (p2 != any.size()) {
				if (nxt == -1 || nxt > any[p2]) {
					nxt = any[p2];
				}
			}
			if (nxt == -1) continue;
			if (dp[mask] == -1 || dp[mask] > nxt + len) {
				dp[mask] = nxt + len;
			}
		}
	}
	return dp.back() != -1;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s;

	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (can(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";
}
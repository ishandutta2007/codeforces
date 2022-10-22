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
	int n, m;
	cin >> n >> m;
	int bad = (m + 1) / 2 + 1;

	vector <int> cnt(n, 0);

	vector <vector <int>> ps(m);
	vector<int> res(m, -1);

	bool badd = false;

	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			--x;
			ps[i].pb(x);
		}
		if (k == 1) {
			if (cnt[ps[i][0]] == bad - 1) {
				badd = true;
			}
			++cnt[ps[i][0]];
			res[i] = ps[i][0];
		}
	}
	if (badd) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < m; ++i) {
		if (res[i] != -1) continue;
		for (int x : ps[i]) {
			if (cnt[x] < bad - 1) {
				++cnt[x];
				res[i] = x;
				break;
			}
		}
		//assert(res[i] != -1);
	}
	cout << "YES\n";
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
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
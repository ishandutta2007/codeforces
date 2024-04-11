#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string a = s, b = t;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a != b) {
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int ps = -1;
		for (int j = i; j < n && ps == -1; j++) {
			if (s[j] == t[i]) ps = j;
		}
		for (int j = ps - 1; j >= i; j--) {
			ans.push_back(j);
			swap(s[j], s[j + 1]);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}
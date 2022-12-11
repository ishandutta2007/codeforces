#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll MD = (ll)1e9 + 7;
const ll P1 = 337;
const ll P2 = 3431;
bool D = false;

vector<ll> POW1, POW2;

void addString(vector<pair<ll, ll>> &h, string s) {
	for (char ch: s) {
		int val = (ch - '0' + 300);
		h.emplace_back((h.back().first * P1 + val) % MD, (h.back().second * P2 + val) % MD);
	}
}

pair<ll, ll> getHash(const vector<pair<ll, ll>> &h, int l, int r) {
	return make_pair(
		(h[r].first - h[l].first * POW1[r - l] + MD * MD) % MD,
		(h[r].second - h[l].second * POW2[r - l] + MD * MD) % MD);
}

void solve() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> h = {{0, 0}};	
	string ans;
	while (n--) {
		string s;
		cin >> s;
		vector<pair<ll, ll>> hh = {{0, 0}};
		addString(hh, s);

		int bst = 0;
		for (int i = 1; i <= (int)s.length(); i++) {
			if ((int)ans.length() >= i && getHash(hh, 0, i) == getHash(h, (int)ans.length() - i, ans.length()))
				bst = i;
		}

		s = s.substr(bst, (int)s.length() - bst);
		ans += s;
		addString(h, s);
	}
	cout << ans << "\n";
}

void init() {
	POW1 = POW2 = {1};
	for (int i = 1; i < N; i++) {
		POW1.push_back(POW1.back() * P1 % MD);
		POW2.push_back(POW2.back() * P2 % MD);
	}
}

int main() {
	init();
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
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
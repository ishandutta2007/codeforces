#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
const ll P1 = 337;
const ll P2 = 733;
bool D = false;

pair<ll, ll> h[N];
ll st1[N], st2[N];

pair<ll, ll> getH(int l, int r) {
	return make_pair((h[r].first - h[l].first * st1[r - l] + MD * MD) % MD,
		(h[r].second - h[l].second * st2[r - l] + MD * MD) % MD);
}

void solve() {
	string s, t;
	cin >> s >> t;

	h[0] = {0, 0};
	st1[0] = st2[0] = 1;
	for (int i = 1; i <= (int)t.length(); i++) {
		st1[i] = (st1[i - 1]) * P1 % MD;
		st2[i] = (st2[i - 1]) * P2 % MD;

		h[i] = make_pair((h[i - 1].first * P1 + t[i - 1] - '0' + 1) % MD, 
					   (h[i - 1].second * P2 + t[i - 1] - '0' + 1) % MD);
	}

	int num0 = 0;
	int num1 = 0;
	for (char ch: s) if (ch == '0') num0++; else num1++;

	int ans = 0;
	int n = t.length();
	for (int len0 = 1; len0 * num0 <= n; len0++) {
		if ((n - len0 * num0) % num1 != 0) continue;
		int len1 = (n - len0 * num0) / num1;
		if (len1 == 0) continue;

		//cout << s << " " << len0 << " " << len1 << "\n";

		int curT = 0;
		pair<ll, ll> h0 = {-1, -1}, h1 = {-1, -1};
		
		bool fail = false;
		for (int i = 0; i < (int)s.length(); i++) {
			//cout << len0 << " " << i << " " << s[i] << endl;
			if (s[i] == '0') {
				if (h0.first == -1) h0 = getH(curT, curT + len0);				
				else {
					if (getH(curT, curT + len0) != h0) fail = true;
				}
				curT += len0;
			} else {				
				if (h1.first == -1) {					
					h1 = getH(curT, curT + len1);									
				} else {
					if (getH(curT, curT + len1) != h1) fail = true;
				}
				curT += len1;
			}
		}
		//if (D) cout << h0.first << " " << h1.first << endl;
		//if (D) cout << h0.second << " " << h1.second << endl;
		if (!fail && h0 != h1) {
			ans++;
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll Q = 31;

const ll INF = 1e9 + 7;

void calc(string &s, vector <ll> &maxq, pair <ll, ll> &pref, pair <ll, ll> &suf) {
	maxq.resize(Q, 0);
	pref = {-1, -1};
	suf = {-1, -1};
	ll now = s[0] - 'a', cnt = 0;
	for (char c : s) {
		ll k = c - 'a';
		if (k != now) {
			maxq[now] = max(maxq[now], cnt);
			if (pref.first == -1) {
				pref = {now, cnt};
			}
			cnt = 1;
			now = k;
		} else {
			cnt++;
		}
	}
	maxq[now] = max(maxq[now], cnt);
	suf = {now, cnt};
	if (cnt == s.size()) {
		pref = suf;
	}
}

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector <ll> maxq;
	pair <ll, ll> prn, sufn;
	calc(s, maxq, prn, sufn);
	for (ll i = 1; i < n; i++) {
		string t;
		cin >> t;
		vector <ll> mn;
		calc(t, mn, prn, sufn);
		if (prn.second == t.size()) {
			maxq[prn.first] += (maxq[prn.first] + 1) * (ll) prn.second; 
			if (maxq[prn.first] >= INF) {
				maxq[prn.first] = INF;
			}
		} else{
			mn[prn.first] = max(mn[prn.first], prn.second + (ll) (maxq[prn.first] > 0));
			mn[sufn.first] = max(mn[sufn.first], sufn.second + (ll) (maxq[sufn.first] > 0));
			//cout << prn.first << " " << sufn.first << " " << prn.second << " " << sufn.second << " " << "\n";
			if (prn.first == sufn.first && maxq[prn.first]) {
				mn[prn.first] = max(mn[prn.first], prn.second + sufn.second + 1);
			}
		}
		/*for (ll i = 0; i < Q; i++) {
			if (maxq[i]) {
				cout << i << " " << maxq[i] << "\n";
			}
		}*/
		for (ll i = 0; i < Q; i++) {
			if (prn.second == t.size() && i == prn.first) continue;
			maxq[i] = min(max(min(maxq[i], 1LL), mn[i]), INF);
		}
		//cout << maxq[0] << "\n";
	}
	ll res = 0;
	for (ll i = 0; i < Q; i++) {
		res = max(res, maxq[i]);
	}
	cout << res << "\n";
}
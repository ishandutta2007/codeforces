#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector <ll> s(n);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
	}
	ll q;
	cin >> q;
	vector <pair <ll, ll> > qs;
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		qs.push_back({r - l + 1, i});
	}
	sort(qs.begin(), qs.end());
	vector <ll> diffs(n - 1, 0);
	sort(s.begin(), s.end());
	for (ll i = 0; i < n - 1; i++) {
		diffs[i] = s[i + 1] - s[i];
	}
	sort(diffs.begin(), diffs.end());
	ll now = 0;
	ll cnt = n;
	ll pr = 0;
	ll res = 0;
	vector <ll> ans(q);
	for (ll i = 0; i < qs.size(); i++) {
		ll val = qs[i].first, id = qs[i].second;
		//cout << val << " " << id << "\n";
		while (now < n - 1 && diffs[now] <= val) {
			res -= pr;
			res += diffs[now];
			now++;
		}
		res += (val - pr) * (diffs.size() - now); 
		ans[id] = res + val;
		pr = val;
	}
	for (ll i = 0; i < q; i++) {
		cout << ans[i] << " ";
	}
}
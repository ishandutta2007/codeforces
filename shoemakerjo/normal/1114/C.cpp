#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pli = pair<ll, int>;

ll n, b;
vector<pli> facts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> b;

	ll cur = b;
	for (ll i = 2LL; i*i <= cur; i+=1LL) {
		if (cur % i != 0) continue;
		int ct = 0;
		while (cur % i == 0) {
			ct++;
			cur /= i;
		}
		facts.push_back(pli(i, ct));
	}

	if (cur > 1LL) {
		facts.push_back(pli(cur, 1));
	}

	ll res = -1LL;
	for (pli vp : facts) {
		cur = vp.first;
		ll og = cur;
		ll ct = vp.second;
		ll cv = 0;

		while (cur <= n) {
			cv += n/cur;
			if (n/cur < og) break;
			cur *= og;
		}

		cv /= ct;
		if (res == -1) {
			res = cv;
		}
		res = min(res, cv);
	}
	cout << res << endl;

}
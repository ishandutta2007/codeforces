#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll BT = (1LL << 40);
const ll INF = 1e18 + 7;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll x;
	cin >> x;

	int large = 0;
	while ((1 << large) <= x) {
		++large;
	}
	--large;

	ll t = (1LL << 40) / x + 1;

	ll a = x * t;

	assert(BT <= a && a < 2 * BT);

	vector <ll> was(1 << 20, -1);

	ll aa = -1, bb = -1;

	while (true) {
		ll now = x * t;
		assert(BT <= now && now < 2 * BT);
		ll val = now;
		for (int i = 39; i >= large; --i) {
			if (val & (1LL << i)) {
				val ^= x << (i - large);
			}
		}
		assert(BT <= val && val < 2 * BT);

		assert(val - BT < (1LL << large));

		ll x = val - BT;
		was[x] = t;
		if (x % 2 && was[x - 1] != -1) {
			aa = was[x - 1], bb = was[x];
			break;
		}
		if (x % 2 == 0 && was[x + 1] != -1) {
			aa = was[x], bb = was[x + 1];
			break;
		}
		++t;
	}
	assert(aa != -1 && bb != -1);

	int large_now = 0;
	while ((1LL << large_now) <= aa || (1LL << large_now) <= bb) {
		++large_now;
	}

	int large_nxt = large_now;
	while ((1LL << large_nxt) <= aa * x || (1LL << large_nxt) <= bb * x) {
		++large_nxt;
	}

	ll now = x;
	vector <pair <ll, ll>> ops;
	for (int i = 1; i < large_nxt; ++i) {
		ops.pb({now, now});
		now *= 2;
	}

	ll cur = 0;
	for (int i = 0; i < large_now; ++i) {
		if (aa & (1LL << i)) {
			ops.pb({cur, (x << i)});
			cur += (x << i);
		}
	}
	assert(cur == aa * x);
	cur = 0;
	for (int i = 0; i < large_now; ++i) {
		if (bb & (1LL << i)) {
			ops.pb({cur, (x << i)});
			cur += (x << i);
		}
	}
	assert(cur == bb * x);

	vector <pair <ll, ll>> xops;

	ll vala = aa * x;
	for (int i = 39; i >= large; --i) {
		if (vala & (1LL << i)) {
			xops.pb({vala, x << (i - large)});
			vala ^= x << (i - large);
		}
	}

	ll valb = bb * x;
	for (int i = 39; i >= large; --i) {
		if (valb & (1LL << i)) {
			xops.pb({valb, x << (i - large)});
			valb ^= x << (i - large);
		}
	}

	cout << ops.size() + xops.size() + 2 << endl;
	cout << x << " ^ " << x << "\n";
	set<ll> values;
	values.insert(x);
	values.insert(0);
	for (auto t : ops) {
		ll x = t.x, y = t.y;
		assert(values.find(x) != values.end() && values.find(y) != values.end());
		values.insert(x + y);
		cout << x << " + " << y << "\n";
	}
	assert(values.find(aa * x) != values.end() && values.find(bb * x) != values.end());

	for (auto t : xops) {
		ll x = t.x, y = t.y;
		assert(values.find(x) != values.end() && values.find(y) != values.end());
		values.insert(x ^ y);
		cout << x << " ^ " << y << "\n";
	}

	assert(values.find(vala) != values.end() && values.find(valb) != values.end());

	cout << vala << " ^ " << valb << endl;
	assert((vala ^ valb) == 1);
}
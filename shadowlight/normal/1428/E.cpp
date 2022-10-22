#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll get_value(ll x, ll k) {
	ll a = x / k, b = x % k;
	ll res = k * a * a;
	res += b * (2 * a + 1);
	return res;
}

struct Value {
	int total, k;
	ll prev;
	ll value;
	int i;
};

bool operator<(Value a, Value b) {
	if (a.prev - a.value == b.prev - b.value) {
		return a.i < b.i;
	}
	return (a.prev - a.value) < (b.prev - b.value);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	k -= n;

	multiset <Value> q;

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		q.insert({x, 1, x * x, get_value(x, 2), i});
		res += x * x;
	}

	for (int i = 0; i < k; ++i) {
		auto val = *q.rbegin();
		q.erase(q.find(val));
		res += val.value - val.prev;
		val.prev = val.value;
		val.k++;
		val.value = get_value(val.total, val.k + 1);
		if (val.total >= val.k + 1) {
			q.insert(val);
		}
	}

	cout << res << "\n";

}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9 + 7;

vector <ll> a;
vector <ll> order;
ll n;
bool can(ll x) {
	order.clear();
	ll now = 0;
	vector <bool> used(n, 0);
	order.push_back(a[now]);
	used[now] = true;
	while (now < n - 1) {
		ll nxt = now + 1;
		if (a[now + 1] - a[now] > x) {
			return false;
		}
		while (nxt + 1 < n && a[nxt + 1] - a[now] <= x) {
			nxt++;
		}
		used[nxt] = true;
		order.push_back(a[nxt]);
		now = nxt;
	}
	for (ll i = n - 2; i >= 0; i--) {
		if (used[i]) continue;
		if (a[now] - a[i] > x) {
			return false;
		}
		order.push_back(a[i]);
		now = i;
	}
	return order.back() - order[0] <= x;
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll lt = -1, rt = INF;
	while (rt - lt > 1) {
		ll mid = (lt + rt) / 2;
		if (can(mid)) {
			rt = mid;
		} else {
			lt = mid;
		}
	}
	can(rt);
	for (ll x : order) {
		cout << x << " ";
	}
}
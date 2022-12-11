#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

bool check(vector<ll> a, ll k, ll res, ll r) {
	queue<pair<ll, ll>> q;
	ll cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		while (!q.empty() && q.front().first <= i) {
			cnt -= q.front().second;
			q.pop();
		}
		a[i] += cnt;
		if (a[i] < res) {
			if (res - a[i] > k) {
				return false;
			}
			k -= res - a[i];
			cnt += res - a[i];
			q.push(make_pair(i + r + r + 1, res - a[i]));
			a[i] = res;
		}
	}
	return true;
}

int main() {
	start();
	ll n, r, k;
	cin >> n >> r >> k;
	vector<ll> a(n);
	vector<pair<ll, ll>> qwer;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		qwer.push_back(make_pair(i - r, val));
		qwer.push_back(make_pair(i + r + 1, -val));
	}
	sort(qwer.begin(), qwer.end());
	ll cnt = 0, ptr = 0;
	for (int i = 0; i < n; ++i) {
		while (ptr < n * 2 && qwer[ptr].first <= i) {
			cnt += qwer[ptr++].second;
		}
		a[i] = cnt;
	}
	ll left = 0;
	ll right = 2e18;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (check(a, k, mid, r)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << left;
	return 0;
}
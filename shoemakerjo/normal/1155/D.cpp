#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 300010;
int n;
ll x;
ll nums[maxn];
ll prefix[maxn];
ll suffix[maxn];
ll psum[maxn];

ll gopos() {
	ll res = 0LL;
	ll csum = 0LL;
	for (int i = 1; i <= n; i++) {
		csum += nums[i];
		res = max(res, csum);
		csum = max(csum, 0LL);
	}
	res = max(res, res*x);
	return res;
}

bool isbet(int a, int b) {
	if (a > b) {
		return !isbet(b, a);
	}

	//want to know if a is better than b
	//we know a <= b
	ll diff = psum[b-1] - psum[a-1];
	diff *= x;
	diff += prefix[a] - prefix[b];
	return diff >= 0LL;
}

ll goneg() {
	//now we multiply by a negative instead
	for (int i = 1; i <= n; i++) {
		prefix[i] = max(0LL, prefix[i-1] + nums[i-1]);
		psum[i] = psum[i-1] + nums[i];
	}
	for (int i = n; i >= 1; i--) {
		suffix[i] = max(0LL, suffix[i+1] + nums[i+1]);
	}

	int bstart = 1;
	ll res = 0LL;
	for (int i = 1; i <= n; i++) {
		if (!isbet(bstart, i)) {
			bstart = i;
		}
		res = max(res, prefix[bstart] + suffix[i] + (psum[i] - psum[bstart-1]) * x);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	if (x > 0) {
			cout << gopos() << endl;
	}
	else {
		ll ans = max(gopos(), goneg());
		cout << ans << endl;
	}

}
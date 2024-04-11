#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, S;
	cin >> n >> S;
	vector<long long> s(n), a(n), b(n);
	vector<pair<long long, long long>> d(n);
	long long ans = 0, best = 0, num = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i] >> b[i];
		d[i].second = s[i];
		d[i].first = b[i] - a[i];
		ans += a[i] * s[i];
		num += s[i];
	}
	sort(d.begin(), d.end());
	long long cbs = 0, bs = 0, ord;
	for (int i = n - 1; i >= 0; i--) {
		if (d[i].first >= 0) {
			ord = ((d[i].second + bs) % S >= num % S && num % S != 0) ? d[i].second : d[i].second - (d[i].second + bs) % S;
			if (ord >= 0)
				best = max(best, ord * d[i].first + cbs);
		}
		else {
			ord = (bs % S >= num % S && num % S != 0) ? 0 : ((S + num - bs) % S); 
			if (ord <= d[i].second)
				best = max(best, ord * d[i].first + cbs);
		}
		cbs += d[i].first * d[i].second;
		bs += d[i].second;
	}
	cout <<ans + best;

}
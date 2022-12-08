#include <bits/stdc++.h>
#define mil 5000000
using namespace std;

bool is_composite[mil+1];
int sp[mil+1];
vector<int> primes;
int BIT[mil+1];

void sieve() {
	for (int i = 0; i <= mil; i++) {
		is_composite[i] = false;
		BIT[i] = 0;
	}
	for (int i = 2; i <= mil; i++) {
		if (!is_composite[i]) {
			primes.push_back(i);
			sp[i] = i;
		}
		for (int j = 0; j < primes.size() && i*primes[j] <= mil; j++) {
			if (!is_composite[i*primes[j]]) {
				is_composite[i*primes[j]] = true;
				sp[i*primes[j]] = primes[j];
			}
			if (i % primes[j] == 0) break;
		}
	}
}

void update(int u, int val) {
	while (u <= mil) {
		BIT[u] += val;
		u += u&(-u);
	}
}

int query(int u) {
	int ans = 0;
	while (u > 0) {
		ans += BIT[u];
		u -= u&(-u);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int t;
	cin >> t;
	int b, a;
	for (int i = 2; i <= mil; i++) {
		// cout << i << endl;
		int cur = i;
		int val = 0;
		while (cur > 1) {
			val++;
			cur/=sp[cur];
		}
		update(i, val);
	}
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int ans = query(a) - query(b);
		cout << ans << '\n';
	}
	// cin >> t;
}